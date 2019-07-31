/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_hendler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:10:05 by Nik               #+#    #+#             */
/*   Updated: 2019/07/31 11:46:41 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**		typedef	struct
**		{
**				int	__dd_fd;				file descriptor associated with directory
**				long	__dd_loc;					offset in current buffer
**				long	__dd_size;					amount of data returned
**				char	*__dd_buf;					data buffer
**				int	__dd_len;						size of data buffer
**				long	__dd_seek;					magic cookie returned
**				__unused long	__padding;		(__dd_rewind space left for bincompat)
**				int	__dd_flags;						flags for readdir
**				__darwin_pthread_mutex_t __dd_lock;	for thread locking
**				struct _telldir *__dd_td;			telldir position recording
**		}	DIR;
**
**		struct group
**		{
**		        char    *gr_name;       group name
**		        char    *gr_passwd;     group password
**		        gid_t   gr_gid;         group id
**		        char    **gr_mem;       group members
**		};
**
** 		struct passwd
** 		{
** 				char    *pw_name;       user name
** 				char    *pw_passwd;     encrypted password
** 				uid_t   pw_uid;         user uid
** 				gid_t   pw_gid;         user gid
** 				time_t  pw_change;      password change time
** 				char    *pw_class;      user access class
** 				char    *pw_gecos;      Honeywell login info
** 				char    *pw_dir;        home directory
** 				char    *pw_shell;      default shell
** 				time_t  pw_expire;      account expiration
** 				int     pw_fields;      internal: fields filled in
** 		};
**		struct stat
**		{
**				dev_t		st_dev;			ID of device containing file
**				mode_t		st_mode;		Mode of file (see below)
**				nlink_t		st_nlink;		Number of hard links
**				__darwin_ino64_t st_ino;	File serial number
**				uid_t		st_uid;			User ID of the file
**				gid_t		st_gid;			Group ID of the file
**				dev_t		st_rdev;		Device ID
**				__DARWIN_STRUCT_STAT64_TIME
**				off_t		st_size;		file size, in bytes
**				blkcnt_t	st_blocks;		blocks allocated for file
**				blksize_t	st_blksize;		optimal blocksize for I/O
**				__uint32_t	st_flags;		user defined flags for file
**				__uint32_t	st_gen;			file generation number
**		};
*/

#include "ft_ls.h"

t_file_list		*new_file_list(void)
{
	t_file_list *new;

	new = (t_file_list *)malloc(sizeof(t_file_list));
	ft_bzero(new, sizeof(t_file_list));
	return (new);
}

void			**add_list(void **arr, t_file_list *list)
{
	void	**new;
	int		i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	new = (void **)malloc(sizeof(void *) * (i + 2));
	i = 0;
	while (arr[i] != NULL)
	{
		new[i] = arr[i];
		i++;
	}
	new[i++] = list;
	new[i] = NULL;
	free(arr);
	return (new);
}

static int		fill_list(t_file_list *list, char *path, char *d_name)
{
	struct stat		info;
	char			*file_name;
	char			*link_path;

	file_name = ft_strjoin_free(ft_strjoin(path, "/"), d_name, 1);
	list->name = ft_strdup(d_name);
	lstat(file_name, &info);
	list->time = info.st_mtimespec.tv_sec;
	list->mode = get_mode(info.st_mode);
	list->usr = getpwuid(info.st_uid)->pw_name;
	list->group = getgrgid(info.st_gid)->gr_name;
	list->links = info.st_nlink;
	list->size = info.st_size;
	if (list->mode[0] == 'l')
	{
		link_path = ft_strnew(50);
		readlink(file_name, link_path, 50);
		list->name = ft_strjoin_free(list->name, " -> ", 1);
		list->name = ft_strjoin_free(list->name, link_path, 3);
	}
	ft_strdel(&file_name);
	return (info.st_blocks);
}

static void		**get_dir(t_ls_flags *flags, DIR *dir_fd, char *path)
{
	struct dirent	*file;
	t_file_list		*list;
	int				allocated_blocks;
	void			**arr;

	arr = (void **)malloc(sizeof(void *));
	*arr = NULL;
	allocated_blocks = 0;
	while ((file = readdir(dir_fd)))
	{
		if (file->d_name[0] == '.' && !flags->hidden)
			continue ;
		list = new_file_list();
		allocated_blocks += fill_list(list, path, file->d_name);
		arr = add_list(arr, list);
	}
	if (flags->l_flag)
		ft_printf("total %d\n", allocated_blocks);
	return (arr);
}

void			dir_hendler(char *dir_name, t_ls_flags *flags)
{
	DIR			*dir_fd;
	void		**arr;

	if(!(dir_fd = opendir(dir_name)))
		return ;
	arr = get_dir(flags, dir_fd, dir_name);
	print(arr, flags);
	closedir(dir_fd);
	if (flags->attach)
		attach_hendler(arr, flags, dir_name);
	del_dir(arr);
}
