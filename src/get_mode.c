/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:10:47 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/31 15:34:47 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define IS_FILE	32768
#define IS_DIR	16384
#define IS_LINK 8192
#define IS_TMP	512
#define U_R		256
#define U_W		128
#define U_X		64
#define G_R		32
#define G_W		16
#define G_X		8
#define O_R		4
#define O_W		2
#define O_X		1

char	get_type(unsigned int mode)
{
	char type;

	if (mode & IS_FILE && mode & IS_DIR)
		type = 's';
	else if (mode & IS_LINK)
		type = 'l';
	else if (mode & IS_DIR)
		type = 'd';
	else
		type = '-';
	return (type);
}

char	*get_mode(unsigned int mode)
{
	char *str_mode;

	str_mode = ft_strnew(10);
	str_mode[0] = get_type(mode);
	str_mode[1] = (mode & U_R) ? 'r' : '-';
	str_mode[2] = (mode & U_W) ? 'w' : '-';
	str_mode[3] = (mode & U_X) ? 'x' : '-';
	str_mode[4] = (mode & G_R) ? 'r' : '-';
	str_mode[5] = (mode & G_W) ? 'w' : '-';
	str_mode[6] = (mode & G_X) ? 'x' : '-';
	str_mode[7] = (mode & O_R) ? 'r' : '-';
	str_mode[8] = (mode & O_W) ? 'w' : '-';
	str_mode[9] = (mode & O_X) ? 'x' : '-';
	str_mode[9] = (mode & IS_TMP) ? 't' : str_mode[9];
	return (str_mode);
}
