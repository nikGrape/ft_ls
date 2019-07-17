/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:00:35 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/16 20:55:09 by vinograd         ###   ########.fr       */
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
** malloc free write - (used in libft)
** following: -l(list), -R(attachments), -a(hiden)
** -r(reverse order) and -t(time order).
*/

#include "ft_ls.h"

void	ft_ls(char *dir_name, t_ls_flags *flags)
{
	DIR			*dir_fd;
	t_file_list	*list;

	dir_fd = opendir(dir_name);
	list = get_list(flags, dir_fd, dir_name);
	list = (flags->time_order) ? time_sort(list) : alphabet_sort(list);
	//print_list(list, flags);
	closedir(dir_fd);
	if (flags->attach)
	{
		while (list->next)
		{
			if ((list->mode[0] == 'd') && !(flags->hidden &&\
			(!ft_strcmp(list->name, ".") || !ft_strcmp(list->name, ".."))))
			{
				ft_printf("%s/%s:\n", dir_name, list->name);
				ft_ls(ft_strjoin(ft_strjoin(dir_name, "/"), list->name), flags);
			}
			list = list->next;
		}
	}
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
