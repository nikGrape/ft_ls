/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:00:35 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/24 18:46:30 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** dirent - ????
** listxattr getxattr
**
** -l(list), -R(attachments), -a(hiden)
** -r(reverse order) and -t(time order)
**
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