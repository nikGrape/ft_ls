/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:00:35 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/20 19:49:19 by vinograd         ###   ########.fr       */
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

	argv++;
	flags = (argc > 1) ? get_flags(*argv) : get_flags("");
	argv += (flags.no_flags) ? 0 : 1;
	if (*argv)
		arguments_hendler(argv, &flags);
	else
		ft_ls_dir(".", &flags);
}

void		arguments_hendler(char **argv, t_ls_flags *flags)
{
	char		new_line;
	DIR			*tmp;

	dir_sort(argv);
	new_line = ft_ls_files(argv, flags);
	while (*argv)
	{
		if (!(tmp = opendir(*argv)))
		{
			argv++;
			continue ;
		}
		closedir(tmp);
		ft_printf("%c%s:\n", new_line, *argv);
		ft_ls_dir(*argv++, flags);
		new_line = '\n';
	}
}

int			ft_ls_dir(char *dir_name, t_ls_flags *flags)
{
	DIR			*dir_fd;
	void		**arr;

	if (!(dir_fd = opendir(dir_name)))
		return (0);
	arr = get_dir(flags, dir_fd, dir_name);
	print(arr, flags);
	closedir(dir_fd);
	if (flags->attach)
		attach_hendler(arr, flags, dir_name);
	del_dir(arr);
	return (1);
}

char		ft_ls_files(char **names, t_ls_flags *flags)
{
	void		**arr;
	t_file_list	*list;
	DIR			*tmp;
	char		ch;

	arr = (void **)malloc(sizeof(void *));
	*arr = NULL;
	while (*names)
	{
		if ((tmp = opendir(*names)))
		{
			names++;
			closedir(tmp);
			continue ;
		}
		if ((list = get_file_info(*names++)))
			arr = add_list(arr, list);
	}
	if (*arr)
		print(arr, flags);
	ch = (*arr) ? '\n' : '\0';
	del_dir(arr);
	return (ch);
}
