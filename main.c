/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 00:25:34 by Nik               #+#    #+#             */
/*   Updated: 2019/07/18 23:19:52 by vinograd         ###   ########.fr       */
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
		ft_ls_for_atributes(argv, &flags);
	else
		ft_ls(".", &flags);
	//while (1);
}

// #include <sys/xattr.h>

// int main()
// {
// 	ssize_t i;
// 	char *list = ft_strnew(50);
// 	i = getxattr("/nfs/2019/v/vinograd/Desktop/ft_ls", list, 50, 0, O_RDWR);
// 	ft_printf("%s\n%ld\n", list, i);
// }