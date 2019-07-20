/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:32:19 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/19 22:07:41 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file_list	*get_file(t_ls_flags *flags, char *file_name)
{
	Stat		info;
	t_file_list	*list;
	char		*link_path;

	list = new_file_list();
	list->name = file_name;
	if ((lstat(file_name, &info)))
	{
		ft_printf("ft_ls: %s: No such file or directory\n", file_name);
		return (NULL);
	}
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
		list->name = ft_strjoin(list->name, " -> ");
		list->name = ft_strjoin_free(list->name, link_path, 3);
	}
	return (list);
}

static char			file_hendler(char **names, t_ls_flags *flags)
{
	void		**arr;
	t_file_list	*list;
	DIR			*tmp;

	arr = (void **)malloc(sizeof(void *));
	*arr = NULL;
	while (*names)
	{
		if ((tmp = opendir(*names)))
		{
			names++;
			closedir(tmp);
			continue ;
		}
		if ((list = get_file(flags, *names++)))
			arr = add_list(arr, list);
	}
	if (*arr)
	{
		sort(arr, flags);
		print(arr, flags);
	}
	//del_dir(arr);
	return (*arr) ? '\n' : '\r';
}

void				atributes_hendler(char **argv, t_ls_flags *flags)
{
	t_file_list	*list;
	char		new_line;
	DIR			*tmp;

	new_line = file_hendler(argv, flags);
	dir_sort(argv, flags);
	while (*argv)
	{
		if (!(tmp = opendir(*argv)))
		{
			argv++;
			continue ;
		}
		closedir(tmp);
		ft_printf("%c%s:\n", new_line, *argv);
		ft_ls(*argv++, flags);
		new_line = '\n';
	}
}
