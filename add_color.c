/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:29:05 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/18 00:29:19 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*add_color(char *name, const char *mode)
{
	char *file_name;

	if (mode[0] == 'd')
		file_name = ft_strjoin_free(ft_strjoin("{bold_cyan}", name),\
		"{eoc}", 1);
	else if (mode[3] == 'x')
		file_name = ft_strjoin_free(ft_strjoin("{red}", name),\
		"{eoc}", 1);
	else
		file_name = ft_strdup(name);
	return (file_name);
}
