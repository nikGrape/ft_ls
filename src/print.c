/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:07:50 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/20 19:54:41 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_frwrd(void **arr, t_ls_flags *flags)
{
	t_file_list *list;
	char		*name;
	int			i;

	i = 0;
	while (*arr != NULL)
	{
		list = (t_file_list *)*arr;
		name = add_color(list->name, list->mode);
		if (!flags->l_flag && list->mode[0] == 'l')
			*(ft_strstr(name, " -> ")) = '\0';
		if (flags->l_flag)
			ft_printf("%s%4d %s  %s%7ld %.12s %s\n",\
			list->mode, list->links, list->usr, list->group,\
			list->size, ctime(&list->time) + 4, name);
		else
			ft_printf("%-20s%c", name, (++i % 6) ? ' ' : '\n');
		arr++;
		ft_strdel(&name);
	}
	if (!flags->l_flag)
		ft_putchar('\n');
}

static void	print_revers(void **arr, t_ls_flags *flags)
{
	t_file_list *list;
	char		*name;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (arr[len])
		len++;
	while (--len >= 0)
	{
		list = (t_file_list *)arr[len];
		name = add_color(list->name, list->mode);
		if (!flags->l_flag && list->mode[0] == 'l')
			*(ft_strstr(name, " -> ")) = '\0';
		if (flags->l_flag)
			ft_printf("%s%4d %s  %s%7ld %.12s %s\n",\
			list->mode, list->links, list->usr, list->group,\
			list->size, ctime(&list->time) + 4, name);
		else
			ft_printf("%-20s%c", name, (++i % 6) ? ' ' : '\n');
		ft_strdel(&name);
	}
	if (!flags->l_flag)
		ft_putchar('\n');
}

void		print(void **arr, t_ls_flags *flags)
{
	sort(arr, flags);
	if (flags->revers_order)
		print_revers(arr, flags);
	else
		print_frwrd(arr, flags);
}
