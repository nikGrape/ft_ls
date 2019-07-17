/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:00:35 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/16 23:34:01 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** dirent - ????
** opendir+		readdir+	closedir+	stat+
** readlink		lstat - (for links)
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
	print(arr, flags);
	closedir(dir_fd);
	if (flags->attach)
		attach_hendler(arr, flags, dir_name);
	//dir_del(arr);
}

int		main(int argc, char **argv)
{
	t_ls_flags	flags;
	char		*path;

	argv++;
	flags = (argc > 1) ? get_flags(*argv) : get_flags("");
	//argv += (flags.no_flags) ? 0 : 1;
	// if ((argc == 1) || (argc == 2 && !flags.no_flags))
	// 	ft_ls(".", &flags);
	// else
	// {
	// 	argc--;
	// 	while (argc)
	// 		ft_ls(argv[--argc], &flags);
	// }
	//path = (argc > 3) ? *argv : ".";
	ft_ls(".", &flags);
}
