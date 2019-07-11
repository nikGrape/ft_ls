/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:00:35 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/11 14:07:53 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "stdio.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/dir.h>

int main(void)
{
	struct stat		ap;
	struct dirent	dir;
	int				fd;
	long long	f;
	fd = open(".", O_RDONLY, 0);
	fstat(fd, &ap);
	ft_printf("fd - %d\n", fd);
	time_t t = ap.st_atimespec.tv_sec;
	char *tm = ctime(&t);
	ft_printf("%s\nsize - %ld\n", tm, ap.st_size);
	int i = read(fd, (char *)&dir, sizeof(dir));
	ft_printf("name - %s\ni = %d\n", dir.d_name, i);
}
