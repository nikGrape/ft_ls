/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_sort_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 21:17:07 by Nik               #+#    #+#             */
/*   Updated: 2019/07/13 13:16:38 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	list_swap(t_file_list *one, t_file_list *two)
{
	t_file_list *tmp;
	
	tmp = one;
	one = two;
	two = tmp;
}


t_file_list		*time_sort_list(t_file_list *head)
{
	t_file_list *max;
	t_file_list *tmp;
	t_file_list *ret;
	int			i;

	i = 0;
	max = head;
	while (head->next)
	{
		tmp = head;
		while (tmp->next)
		{
			if (max->created < tmp->created)
				list_swap(max, tmp);
			tmp = tmp->next;
		}
		if (i++ == 0)
			ret = max;
		head = head->next;
	}
	return (ret);
}
