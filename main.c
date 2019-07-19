/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 00:25:34 by Nik               #+#    #+#             */
/*   Updated: 2019/07/19 15:57:06 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	typedef struct
**	{
**		int	__dd_fd;				file descriptor associated with directory
**		long	__dd_loc;					offset in current buffer
**		long	__dd_size;					amount of data returned
**		char	*__dd_buf;					data buffer
**		int	__dd_len;						size of data buffer
**		long	__dd_seek;					magic cookie returned
**		__unused long	__padding;		(__dd_rewind space left for bincompat)
**		int	__dd_flags;						flags for readdir
**		__darwin_pthread_mutex_t __dd_lock;	for thread locking
**		struct _telldir *__dd_td;			telldir position recording
**	}	DIR;
*/

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_ls_flags	flags;
	char		*path;

	argv++;
	flags = (argc > 1) ? get_flags(*argv) : get_flags("");
	argv += (flags.no_flags) ? 0 : 1;
	if (*argv)
		ft_ls_for_atributes(argv, &flags);
	else
		ft_ls(".", &flags);
	//while (1);
}

// int main()
// {
// 	t_file_list list;
// 	Stat		info;
// 	DIR			*dir;

// 	dir = opendir("link1");
// 	if (dir == NULL)
// 	{
// 		ft_printf("not a dir\n");
// 		return (1);
// 	}
// 	ft_printf("%d\n", dir->__dd_td);
// 	lstat("libft", &info);
// 	ft_printf("%s\n", get_mode(info.st_mode));
// }
