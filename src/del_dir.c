/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 23:03:43 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/18 01:21:31 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	list_del(t_file_list *list)
{
	ft_strdel(&list->name);
	ft_strdel(&list->mode);
	free(list);
}

void		del_dir(void **arr)
{
	t_file_list *list;
	void		**tmp;

	if (arr)
	{
		tmp = arr;
		while (*tmp)
		{
			list = (t_file_list *)*tmp;
			list_del(list);
			tmp++;
		}
		free(arr);
	}
}
