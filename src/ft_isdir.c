/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:03:08 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/24 21:07:24 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_isdir(char *file_name)
{
	DIR		*tmp;

	tmp = opendir(file_name);
	if (tmp)
	{
		closedir(tmp);
		return (1);
	}
	return (0);
}
