/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:00:35 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/31 12:00:59 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** dirent - ????
** allowed functions:
** 1 opendir	2 readdir	3 closedir
** 4 stat	5 lstat -the same as 'stat' but does not follow links
** 6 getpwuid	7 getgrgid
** 8 listxattr 9 getxattr - I don't know what it is. Did not use
** 10 time 11 ctime
** 12 readlink - get the link path readlink(link_name, str_buffer, buf_size);
** 13 perror 14 strerror 15 exit
**
** -l(show whole information), -R(attachments), -a(hiden)
** -r(reverse order) and -t(time order)
** -L(supress links) turned on default with directory links sent as a param
**	./ft_ls -l ~/Library/Application\ Support/Code - socet link example
**
** mode =>			-dl-***t-rwx-rwx-rwx => '-' means file
** directory 		010-0000-111-101-101
** file 			100-0000-110-100-100
** simbolic link 	101-0000-111-101-101
** tmp_dir	    	010-0001-111-111-111 - last 'x' would be 't'
** socet_link 		110-0000-111-101-101 - has both bits dir and file
** 					
*/

#include "ft_ls.h"

int			main(int argc, char **argv)
{
	t_ls_flags	flags;
	char		new_line;

	argv++;
	if (argc > 1)
		flags = get_flags(argv);
	argv += flags.step;
	if (*argv)
	{
		new_line = ft_ls_files(argv, &flags);
		ft_ls_dir(argv, &flags, new_line);
	}
	else
		dir_hendler(".", &flags);
}
