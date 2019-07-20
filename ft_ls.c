/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:00:35 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/19 22:33:27 by vinograd         ###   ########.fr       */
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

int				ft_ls(char *dir_name, t_ls_flags *flags)
{
	t_file_list *list;
	DIR			*dir_fd;
	char		*path;
	void		**arr;

	if (!(dir_fd = opendir(dir_name)))
		return (0);
	arr = get_dir(flags, dir_fd, dir_name);
	sort(arr, flags);
	print(arr, flags);
	closedir(dir_fd);
	if (flags->attach)
		attach_hendler(arr, flags, dir_name);
	del_dir(arr);
	return (1);
}
