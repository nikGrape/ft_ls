/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:29:05 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/16 14:30:57 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*add_color(char *name, const char *mode)
{
	char *file_name;

	file_name = ft_strdup(name);
	if (mode[0] == 'd')
		file_name = ft_strjoin_free(ft_strjoin_free("{bold_cyan}",\
		file_name, 2), "{eoc}", 1);
	else if (mode[3] == 'x')
		file_name = ft_strjoin_free(ft_strjoin_free("{red}",\
		file_name, 2), "{eoc}", 1);
	return (file_name);
}
