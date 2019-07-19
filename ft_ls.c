/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:00:35 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/18 22:53:40 by vinograd         ###   ########.fr       */
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

void	ft_ls(char *dir_name, t_ls_flags *flags)
{
	t_file_list *list;
	DIR			*dir_fd;
	char		*path;
	void		**arr;

	dir_fd = opendir(dir_name);
	arr = get_dir(flags, dir_fd, dir_name);
	sort(arr, flags);
	print(arr, flags);
	closedir(dir_fd);
	if (flags->attach)
		attach_hendler(arr, flags, dir_name);
	del_dir(arr);
}

void	ft_ls_for_atributes(char **atributes, t_ls_flags *flags)
{
	while (*atributes)
	{
		ft_printf("%s\n", *atributes);
		ft_ls(*atributes++, flags);
		ft_printf("\n");
	}
}
