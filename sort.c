/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:17:04 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/19 22:00:42 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	alphabet_sort(void **arr)
{
	t_file_list *list;
	t_file_list *max;
	void		*tmp;
	int			i;
	int			j;

	j = 0;
	while (arr[j])
	{
		max = (t_file_list *)arr[j];
		i = j + 1;
		while (arr[i])
		{
			list = (t_file_list *)arr[i];
			if (ft_strcmp(max->name, list->name) > 0)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				max = (t_file_list *)tmp;
			}
			i++;
		}
		j++;
	}
}

void	time_sort(void **arr)
{
	t_file_list *list;
	t_file_list *max;
	void		*tmp;
	int			i;
	int			j;

	j = 0;
	while (arr[j])
	{
		max = (t_file_list *)arr[j];
		i = j + 1;
		while (arr[i])
		{
			list = (t_file_list *)arr[i];
			if (max->time < list->time)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				max = (t_file_list *)tmp;
			}
			i++;
		}
		j++;
	}
}

void	sort(void **arr, t_ls_flags *flags)
{
	if (flags->time_order)
		time_sort(arr);
	else
		alphabet_sort(arr);
}

void	dir_sort(char **argv, t_ls_flags *flags)
{
	char		*tmp;
	int			i;
	int			j;

	j = 0;
	while (argv[j])
	{
		i = j + 1;
		while (argv[i])
		{
			if (ft_strcmp(argv[j], argv[i]) > 0)
			{
				tmp = argv[i];
				argv[i] = argv[j];
				argv[j] = tmp;
			}
			i++;
		}
		j++;
	}
}
