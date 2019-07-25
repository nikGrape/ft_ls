/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:12:45 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/24 21:11:20 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** following: -l(list), -R(attachments), -a(hiden)
** -r(reverse order) and -t(create time order)
*/

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/dir.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>

typedef struct
{
	char		l_flag;
	char		attach;
	char		hidden;
	char		revers_order;
	char		time_order;
	char		step;
}				t_ls_flags;
typedef struct	s_ls
{
	long		time;
	char		*name;
	char		*mode;
	size_t		size;
	char		*group;
	char		*usr;
	int			links;
}				t_file_list;

void			dir_hendler(char *dir_name, t_ls_flags *flags);
char			ft_ls_files(char **names, t_ls_flags *flags);
void			ft_ls_dir(char **argv, t_ls_flags *flags, char new_line);
void			**add_list(void **arr, t_file_list *list);
t_ls_flags		get_flags(char **s);
char			*get_mode(unsigned int mode);
t_file_list		*get_file_info(char *file_name);
void			ls_errors(int err, char *file_name);
void			print(void **arr, t_ls_flags *flags);
void			sort(void **arr, t_ls_flags *flags);
void			dir_sort(char **argv);
char			*add_color(char *name, const char *mode);
void			attach_hendler(void **arr, t_ls_flags *flags, char *dir_name);
void			del_dir(void **arr);
t_file_list		*new_file_list(void);
int				ft_isdir(char *file_name);

#endif
