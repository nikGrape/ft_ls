/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:10:05 by Nik               #+#    #+#             */
/*   Updated: 2019/07/15 17:56:03 by vinograd         ###   ########.fr       */
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

static char			*add_color(char *name, const char *mode, char g_flag)
{
	char *file_name;
	
	file_name = ft_strdup(name); 
	if (mode[0] == 'd' && g_flag)
		file_name = ft_strjoin_free(ft_strjoin_free("{bold_cyan}", file_name, 2), "{eoc}", 1);
	else if (mode[3] == 'x' && g_flag)
		file_name = ft_strjoin_free(ft_strjoin_free("{red}", file_name, 2), "{eoc}", 1);
	return (file_name);
}

t_file_list			*get_list(t_ls_flags *flags, DIR *dir_fd, char *dir_name)
{
	struct stat	info;		//file information container
	Dirent		*file;		//name and ino container
	t_file_list	*head;
	t_file_list	*list;
	int i = 1;
	head = new_file_list(NULL);
	list = head;
	while ((file = readdir(dir_fd)))
	{
		if (file->d_name[0] == '.' && !flags->hidden)
			continue ;
		list->next = new_file_list(list);//???
		stat(ft_strjoin(ft_strjoin(dir_name, "/"), file->d_name), &info);
		list->created = info.st_mtimespec.tv_sec;
		list->time = ft_strdup(ctime(&(info.st_mtimespec.tv_sec)));
		list->mode = get_mode(info.st_mode);
		list->name = ft_strdup(file->d_name);
		list->usr = ft_strdup(getpwuid(info.st_uid)->pw_name);
		list->group = ft_strdup(getgrgid(info.st_gid)->gr_name);
		list->links = info.st_nlink;
		list->size = info.st_size;
		list = list->next;
		i++;
	}
	//free(list);
	//list = NULL;
	ft_printf("%d\n", i);
	return (head);
}
