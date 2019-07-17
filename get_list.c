/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:10:05 by Nik               #+#    #+#             */
/*   Updated: 2019/07/16 20:57:33 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**		struct group *getgrgid(gid_t gid);
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
**		dev_t		st_dev;			ID of device containing file
**		mode_t		st_mode;		Mode of file (see below)
**		nlink_t		st_nlink;		Number of hard links
**		__darwin_ino64_t st_ino;	File serial number
**		uid_t		st_uid;			User ID of the file
**		gid_t		st_gid;			Group ID of the file
**		dev_t		st_rdev;		Device ID
**		__DARWIN_STRUCT_STAT64_TIME
**		off_t		st_size;		file size, in bytes
**		blkcnt_t	st_blocks;		blocks allocated for file
**		blksize_t	st_blksize;		optimal blocksize for I/O
**		__uint32_t	st_flags;		user defined flags for file
**		__uint32_t	st_gen;			file generation number
**		}
*/
#include "ft_ls.h"

static t_file_list	*new_file_list(t_file_list *back)
{
	t_file_list *new;

	new = (t_file_list *)malloc(sizeof(t_file_list));
	ft_bzero(new, sizeof(t_file_list));
	new->next = NULL;
	new->back = back;
	return (new);
}

void				**add_list(void **arr, t_file_list *list)
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

t_file_list			*get_list(t_ls_flags *flags, DIR *dir_fd, char *path)
{
	Stat		info;		//file information container
	Dirent		*file;		//name and ino container
	t_file_list	*head;
	t_file_list	*list;
	int			allocated_blocks;
	void		**arr;

	arr = (void **)malloc(sizeof(void *));
	*arr = NULL;
	allocated_blocks = 0;
	head = new_file_list(NULL);
	list = head;
	while ((file = readdir(dir_fd)))
	{
		if (file->d_name[0] == '.' && !flags->hidden)
			continue ;
		list->next = new_file_list(list);
		list->name = ft_strdup(file->d_name);
		stat(ft_strjoin_free(ft_strjoin(path, "/"), list->name, 1), &info);
		list->time = info.st_mtimespec.tv_sec;
		list->mode = get_mode(info.st_mode);
		list->usr = getpwuid(info.st_uid)->pw_name;
		list->group = getgrgid(info.st_gid)->gr_name;
		list->links = info.st_nlink;
		list->size = info.st_size;
		allocated_blocks += info.st_blocks;
		arr = add_list(arr, list);
		list = list->next;
	}
	ft_printf("total %d\n", allocated_blocks);
	while (*arr != NULL)
	{
		t_file_list *list;
		list = (t_file_list *)*arr;
		ft_printf("%s\n", list->name);
		arr++;
	}
	return (head);
}
