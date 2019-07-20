/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:11:14 by Nik               #+#    #+#             */
/*   Updated: 2019/07/19 22:30:34 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** following: -l(list), -R(attachments), -a(hiden), -r and -t
*/
#include "ft_ls.h"

static int	is_flag(char ch)
{
	if (ch == 'l' || ch == 'R' || ch == 'a'\
	|| ch == 'r' || ch == 't' || ch == 'G')
		return (1);
	return (0);
}

static void	flag_analizer(t_ls_flags *flags, char *s)
{
	while (is_flag(*s))
	{
		if (*s == 'l')
			flags->l_flag = 1;
		if (*s == 'R')
			flags->attach = 1;
		if (*s == 'a')
			flags->hidden = 1;
		if (*s == 'r')
			flags->revers_order = 1;
		if (*s == 't')
			flags->time_order = 1;
		if (*s == 'G')
			flags->colors = 1;
		if (*s == 'L')
			flags->links = 1;
		s++;
	}
	if (*s != '\0')
		ls_errors(3, s);
}

t_ls_flags	get_flags(char *s)
{
	t_ls_flags flags;

	ft_bzero(&flags, sizeof(t_ls_flags));
	if (*s++ == '-')
		flag_analizer(&flags, s);
	else
		flags.no_flags = 1;
	return (flags);
}
