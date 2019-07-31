/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attachment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 23:27:49 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/31 02:30:15 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	attach_hendler(void **arr, t_ls_flags *flags, char *dir_name)
{
	t_file_list	*list;
	char		*path;

	while (*arr)
	{
		list = (t_file_list *)*arr;
		if ((list->mode[0] == 'd') && !(flags->hidden &&\
		(!ft_strcmp(list->name, ".") || !ft_strcmp(list->name, ".."))))
		{
			path = ft_strjoin_free(ft_strjoin(dir_name, "/"), list->name, 1);
			// if (!(ft_isdir(path)))
			// {
			// 	arr++;
			// 	continue ;
			// }
			ft_printf("\n%s:\n", path);
			dir_hendler(path, flags);
			ft_strdel(&path);
		}
		arr++;
	}
}
