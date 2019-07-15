/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_sort_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 21:17:07 by Nik               #+#    #+#             */
/*   Updated: 2019/07/13 14:49:02 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	next_swap(t_file_list *one, t_file_list *two)
{
	t_file_list *tmp;
	
	tmp = one->next;
	one->next = two->next;
	two->next = tmp;
}

void	list_swap(t_file_list *one, t_file_list *two)
{
	next_swap(one->back, two->back);
	next_swap(one, two);
}


t_file_list		*time_sort_list(t_file_list *head)
{
	t_file_list *max;
	t_file_list *tmp;
	t_file_list *ret;
	t_file_list *max_next;
	int			i;

	i = 0;
	ft_printf("We are here in time sort!\n");
	max = head;
	while (max->next)
	{
		tmp = max->next;
		while (tmp->next)
		{
			if (max->created < tmp->created)
			{
				list_swap(max, tmp);
				max_next = max->next;
				max = tmp;
				tmp = max_next;
			}
			else
				tmp = tmp->next;
		}
		if (i++ == 0)
			ret = max;
		max = max->next;
	}
	ft_printf("%d\n", i);
	return (ret);
}
