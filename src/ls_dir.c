/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:59:11 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/24 21:14:04 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		arr_len(void **arr)
{
	int i;

	i = 0;
	while (*arr++)
		i++;
	return (i);
}

static void		print_dir(void **arr, t_ls_flags *flags, char new_line)
{
	int len;

	sort(arr, flags);
	len = arr_len(arr);
	while (*arr)
	{
		if (len > 1 || new_line)
			ft_printf("%c%s:\n", new_line, ((t_file_list *)*arr)->name);
		dir_hendler(((t_file_list *)*arr++)->name, flags);
		new_line = '\n';
	}
}

void			ft_ls_dir(char **argv, t_ls_flags *flags, char new_line)
{
	void		**arr;
	t_file_list	*list;

	arr = (void **)malloc(sizeof(void *));
	*arr = NULL;
	while (*argv)
	{
		if (!(ft_isdir(*argv)))
		{
			argv++;
			continue ;
		}
		if ((list = get_file_info(*argv++)))
			arr = add_list(arr, list);
	}
	if (*arr)
		print_dir(arr, flags, new_line);
	del_dir(arr);
}
