/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:09:28 by Nik               #+#    #+#             */
/*   Updated: 2019/07/16 17:40:03 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	frw_print_list(t_file_list *list, t_ls_flags *flags)
{
	char *name;

	while (list->next != NULL)
	{
		name = (flags->colors) ? add_color(list->name, list->mode) : list->name;
		if (flags->l_flag)
			ft_printf("%s%4d %s  %s%7ld %.12s %s\n",\
			list->mode, list->links, list->usr, list->group,\
			list->size, ctime(&list->time) + 4, name);
		else
			ft_printf("%s\t", name);
		list = list->next;
		if (flags->colors)
			ft_strdel(&name);
	}
	if (!flags->l_flag)
		ft_putchar('\n');
}

static void	rev_print_list(t_file_list *list, t_ls_flags *flags)
{
	char *name;

	while (list->next->next)
		list = list->next;
	while (list)
	{
		name = (flags->colors) ? add_color(list->name, list->mode) : list->name;
		if (flags->l_flag)
			ft_printf("%s%4d %s  %s%7ld %.12s %s\n",\
			list->mode, list->links, list->usr, list->group,\
			list->size, ctime(&list->time) + 4, name);
		else
			ft_printf("%s\t", name);
		list = list->back;
		if (flags->colors)
			ft_strdel(&name);
	}
	if (!flags->l_flag)
		ft_putchar('\n');
}

void		print_list(t_file_list *head, t_ls_flags *flags)
{
	if (flags->revers_order)
		rev_print_list(head, flags);
	else
		frw_print_list(head, flags);
}
