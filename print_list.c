/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:09:28 by Nik               #+#    #+#             */
/*   Updated: 2019/07/13 13:14:17 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"	

void	frw_print_list(t_file_list *list, char l_flag)
{		
	while (list->next != NULL)
	{
		if (l_flag)
			ft_printf("%s%4d %s  %s%7ld %.12s %s\n",\
			list->mode, list->links, list->usr , list->group, list->size, list->time + 4, list->name);
		else
			ft_printf("%s\t", list->name);
		list = list->next;
	}
	if (!l_flag)
		ft_putchar('\n');
}

void	rev_print_list(t_file_list *list, char l_flag)
{
	while (list->next)
		list = list->next;
	list = list->back;			//??
	while (list)
	{
		if (l_flag)
			ft_printf("%s%4d %s  %s%7ld %.12s %s\n",\
			list->mode, list->links, list->usr , list->group, list->size, list->time + 4, list->name);
		else
			ft_printf("%s\t", list->name);	
		list = list->back;
	}
}

void	attach_print_list(t_file_list *list, t_ls_flags *flags)
{
	
}

void	print_list(t_file_list *list, t_ls_flags *flags)
{
	 if (flags->time_order)
	 	list = time_sort_list(list);
	if (flags->revers)
		rev_print_list(list, flags->list);
	else
		frw_print_list(list, flags->list);
}