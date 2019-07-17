/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 21:17:07 by Nik               #+#    #+#             */
/*   Updated: 2019/07/16 20:12:13 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		back_swap(t_file_list *one, t_file_list *two)
{
	t_file_list *tmp;

	tmp = one->back;
	one->back = two->back;
	two->back = tmp;
}

static void		next_swap(t_file_list *one, t_file_list *two)
{
	t_file_list *tmp;

	tmp = one->next;
	one->next = two->next;
	two->next = tmp;
}

static void		list_swap(t_file_list *one, t_file_list *two)
{
	next_swap(one->next, two->next);
	next_swap(one, two);
}

t_file_list		*time_sort(t_file_list *head)
{
	t_file_list *max;
	t_file_list *tmp;
	t_file_list *ret;
	t_file_list *max_next;
	int			i;

	i = 0;
	max = head;
	while (max->next->next)
	{
		tmp = max->next;
		while (tmp->next->next)
		{
			if (max->next->time < tmp->next->time)
				list_swap(max, tmp);
			tmp = tmp->next;
		}
		if (i++ == 0)
			ret = max;
		max = max->next;
	}
	return (head);
}

t_file_list		*alphabet_sort(t_file_list *head)
{
	return (head);
}
