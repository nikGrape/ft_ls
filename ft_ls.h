/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:12:45 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/16 23:31:13 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** following: -l(list), -R(attachments), -a(hiden)
** -r(reverse order) and -t(create time order)
*/

#ifndef FT_LS_H
# define FT_LS_H

# include "stdio.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/dir.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>

typedef struct dirent	Dirent;
typedef struct stat		Stat;
typedef struct
{
	char		l_flag;
	char		attach;
	char		hidden;
	char		revers_order;
	char		time_order;
	char		colors;
	char		no_flags;
}				t_ls_flags;
typedef struct	s_ls
{
	long		time;
	char		*name;	//need free!
	char		*mode;	//need free!
	size_t		size;
	char		*group;
	char		*usr;
	int			links;
	struct s_ls	*next;
	struct s_ls *back;
}				t_file_list;

void			ft_ls(char *dir_name, t_ls_flags *flags);
t_ls_flags		get_flags(char *s);
void			**get_dir(t_ls_flags *flags, DIR *dir_fd, char *path);
char			*get_mode(unsigned int mode);
void			ls_errors(int err, char *file_name);
void			print(void **arr, t_ls_flags *flags);
void			sort(void **arr, t_ls_flags *flags);
char			*add_color(char *name, const char *mode);
void			attach_hendler(void **arr, t_ls_flags *flags, char *dir_name);
void			dir_del(void **arr);

#endif
