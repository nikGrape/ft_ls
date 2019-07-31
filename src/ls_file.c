/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:32:19 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/31 02:31:03 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file_list		*get_file_info(char *file_name)
{
	struct stat	info;
	t_file_list	*list;
	char		*link_path;

	if ((lstat(file_name, &info)))
	{
		ft_printf("ft_ls: %s: No such file or directory\n", file_name);
		return (NULL);
	}
	list = new_file_list();
	list->name = ft_strdup(file_name);
	list->time = info.st_mtimespec.tv_sec;
	list->mode = get_mode(info.st_mode);
	list->usr = getpwuid(info.st_uid)->pw_name;
	list->group = getgrgid(info.st_gid)->gr_name;
	list->links = info.st_nlink;
	list->size = info.st_size;
	if (list->mode[0] == 'l' && !ft_isdir(file_name))
	{
		link_path = ft_strnew(50);
		readlink(list->name, link_path, 50);
		list->name = ft_strjoin_free(list->name, " -> ", 1);
		list->name = ft_strjoin_free(list->name, link_path, 3);
	}
	return (list);
}

char			ft_ls_files(char **names, t_ls_flags *flags)
{
	void		**arr;
	t_file_list	*list;
	char		ch;

	ch = '\0';
	arr = (void **)malloc(sizeof(void *));
	*arr = NULL;
	while (*names)
	{
		if (ft_isdir(*names))
		{
			names++;
			continue ;
		}
		if ((list = get_file_info(*names++)))
			arr = add_list(arr, list);
		ch = '\r';
	}
	if (*arr)
	{
		print(arr, flags);
		ch = '\n';
	}
	del_dir(arr);
	return (ch);
}
