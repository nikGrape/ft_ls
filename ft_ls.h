/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:12:45 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/13 13:11:37 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* following: -l(list), -R(attachments), -a(hiden), -r(reverse order) and -t(create time). */

#ifndef FT_LS
# define FT_LS

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
	char	list;
	char	attach;
	char	hidden;
	char	revers;
	char	time_order;
	char	colors;
	char	one;
	char	no_flags;
}				t_ls_flags;
typedef struct	s_ls
{
	long		created;
	char		*name;	//free
	char		*time;	//free
	char		*mode;	//free
	size_t		size;
	char		*group;
	char		*usr;
	int			links;
	struct s_ls	*next;
	struct s_ls *back;
}				t_file_list;


char			*get_mode(unsigned int mode);
void			ls_errors(int err, char *file_name);
t_file_list		*get_list(t_ls_flags *flags, DIR *dir_fd);
t_ls_flags		get_flags(char *s);
void			print_list(t_file_list *list, t_ls_flags *flags);
void			ft_ls(char *dir_name, t_ls_flags *flags);
t_file_list		*time_sort_list(t_file_list *list);

#endif
