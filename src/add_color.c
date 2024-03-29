/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:29:05 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/31 15:00:08 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*link_color(char *name)
{
	char	*file_name;
	char	*link;
	int		link_len;

	link_len = ft_strlen(name) + ft_strlen("{magenta}") + ft_strlen("{eoc}");
	file_name = ft_strnew(link_len);
	ft_strcat(file_name, "{magenta}");
	ft_strcat(file_name, name);
	link = ft_strstr(file_name, " -> ");
	ft_strcpy(link, "{eoc}");
	link = ft_strstr(name, " -> ");
	ft_strcat(file_name, link);
	return (file_name);
}

char		*add_color(char *name, const char *mode)
{
	char	*file_name;

	if (mode[0] == 'd')
		file_name = ft_strjoin_free(ft_strjoin("{bold_cyan}", name),\
		"{eoc}", 1);
	else if (mode[0] == 's')
		file_name = ft_strjoin_free(ft_strjoin("{green}", name),\
		"{eoc}", 1);
	else if (mode[0] == 'l')
		file_name = link_color(name);
	else if (mode[3] == 'x')
		file_name = ft_strjoin_free(ft_strjoin("{red}\0", name),\
		"{eoc}\0", 1);
	else
		file_name = ft_strdup(name);
	return (file_name);
}
