/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:00:35 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/19 15:59:10 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** dirent - ????
** opendir+		readdir+	closedir+	stat+
** readlink+		lstat+ - (for links)
** getpwuid+ getgrgid+ - (user and grup information in struct passwd)
** listxattr getxattr
** time		ctime+
** perror strerror exit - (errors_functions)
**
** following: -l(list), -R(attachments), -a(hiden)
** -r(reverse order) and -t(time order).
*/

#include "ft_ls.h"

int				ft_ls(char *dir_name, t_ls_flags *flags)
{
	t_file_list *list;
	DIR			*dir_fd;
	char		*path;
	void		**arr;

	if (!(dir_fd = opendir(dir_name)))
		return (0);
	arr = get_dir(flags, dir_fd, dir_name);
	sort(arr, flags);
	print(arr, flags);
	closedir(dir_fd);
	if (flags->attach)
		attach_hendler(arr, flags, dir_name);
	del_dir(arr);
	return (1);
}

void			ft_ls_for_atributes(char **atributes, t_ls_flags *flags)
{
	char	**name;
	void	**arr;
	t_file_list	*list;
	char		new_line;

	arr = (void **)malloc(sizeof(void *));
	*arr = NULL;
	name = atributes;
	while (*name)
	{
		if (opendir(*name))
		{
			name++;
			continue ;
		}
		list = get_file(flags, *name++);
		arr = add_list(arr, list);
	}
	if (*arr)
	{
		sort(arr, flags);
		print(arr, flags);
	}
	new_line = (*arr) ? '\n' : '\r';
	name = atributes;
	while (*name)
	{
		if (!opendir(*name))
		{
			name++;
			continue ;
		}
		ft_printf("%c%s:\n", new_line, *name);
		ft_ls(*name++, flags);
		new_line = '\n';
	}
}
