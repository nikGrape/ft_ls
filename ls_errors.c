/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:22:34 by Nik               #+#    #+#             */
/*   Updated: 2019/07/16 23:39:03 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_errors(int err, char *message)
{
	if (err == 1)
		ft_printf("ft_ls: %s: No such file or directory\n", message);
	else if (err == 2)
		ft_printf("MALLOC ERROR\n");
	else if (err == 3)
		ft_printf("ls: illegal option - %c\n\
		usge: ft_ls [-GRlart] [file ...]\n", *message);
	exit(1);
}
