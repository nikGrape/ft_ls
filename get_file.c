/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:32:19 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/19 15:29:01 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file_list		*get_file(t_ls_flags *flags, char *file_name)
{
	Stat		info;
	t_file_list	*list;
	char		*link_path;

	list = new_file_list();
	list->name = file_name;
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
		readlink(list->name, link_path, 50);
		list->name = ft_strjoin_free(list->name, " -> ", 1);
		list->name = ft_strjoin_free(list->name, link_path, 2);
	}
	return (list);
}
