/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:11:14 by Nik               #+#    #+#             */
/*   Updated: 2019/07/16 14:59:29 by vinograd         ###   ########.fr       */
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

t_ls_flags	get_flags(char *s)
{
	t_ls_flags flags;

	ft_bzero(&flags, sizeof(t_ls_flags));
	if (*s == '-')
	{
		s++;
		while (is_flag(*s))
		{
			if (*s == 'l')
				flags.l_flag = 1;
			if (*s == 'R')
				flags.attach = 1;
			if (*s == 'a')
				flags.hidden = 1;
			if (*s == 'r')
				flags.revers_order = 1;
			if (*s == 't')
				flags.time_order = 1;
			if (*s == 'G')
				flags.colors = 1;
			s++;
		}
		if (*s != '\0')
			ls_errors(3, s);
	}
	else
		flags.no_flags = 1;
	return (flags);
}
