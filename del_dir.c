/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 23:03:43 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/16 23:18:14 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	list_del(t_file_list *list)
{
	ft_strdel(&list->name);
	ft_strdel(&list->mode);
	free(list);
}

void		dir_del(void **arr)
{
	t_file_list *list;
	void		**tmp;

	if (arr)
	{
		tmp = arr;
		while (*tmp)
		{
			list = (t_file_list *)*tmp;
			tmp++;
		}
		free(arr);
	}
}
