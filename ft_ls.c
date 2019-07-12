/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:00:35 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/11 21:55:23 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** opendir+		readdir+	closedir+	stat+ lstat
** getpwuid getgrgid listxattr getxattr
** time ctime readlink
** perror strerror exit - errors_functions
** malloc free write - used in libft
*/

#include "ft_ls.h"

int main(int argc, char **argv)
{
	struct stat		ap;
	struct dirent	*dir;
	DIR				*dire;
	time_t			tim;
	size_t			size;
	char			*mode;
	dire = opendir(".");
	while ((dir = readdir(dire)))
	{
		stat(dir->d_name, &ap);
		tim = ap.st_atimespec.tv_sec;
		mode = mode_redactor(ap.st_mode);
		ft_printf("%s%4ld%9s%12s%7ld %.12s %s\n",\
		mode, ap.st_nlink, "username" ,"0000_month", ap.st_size, ctime(&tim) + 4, dir->d_name);
	}
	closedir(dire);
}
