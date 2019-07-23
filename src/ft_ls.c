/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:00:35 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/22 18:15:17 by vinograd         ###   ########.fr       */
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

int			arr_len(void **arr)
{
	int i;

	i = 0;
	while (*arr++)
		i++;
	return (i);
}

void		print_dir(void **arr, t_ls_flags *flags, char new_line)
{
	int len;

	sort(arr, flags);
	len = arr_len(arr);
	while (*arr)
	{
		if (len > 1)
			ft_printf("%c%s:\n", new_line, ((t_file_list *)*arr)->name);
		dir_hendler(((t_file_list *)*arr++)->name, flags);
		new_line = '\n';
	}
}

void		ft_ls_dir(char **argv, t_ls_flags *flags, char new_line)
{
	void		**arr;
	t_file_list	*list;
	DIR			*tmp;

	arr = (void **)malloc(sizeof(void *));
	*arr = NULL;
	while (*argv)
	{
		if (!(tmp = opendir(*argv)))
		{
			argv++;
			continue ;
		}
		closedir(tmp);
		if ((list = get_file_info(*argv++)))
			arr = add_list(arr, list);
	}
	if (*arr)
		print_dir(arr, flags, new_line);
	del_dir(arr);
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
