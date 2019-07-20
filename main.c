/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 00:25:34 by Nik               #+#    #+#             */
/*   Updated: 2019/07/19 22:33:11 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_ls_flags	flags;
	char		*path;

	argv++;
	flags = (argc > 1) ? get_flags(*argv) : get_flags("");
	argv += (flags.no_flags) ? 0 : 1;
	if (*argv)
		atributes_hendler(argv, &flags);
	else
		ft_ls(".", &flags);
	while (1);
}
