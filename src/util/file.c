/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:44:33 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/25 21:08:49 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

void	save(t_engine o)
{
	printf("save: %li\n", sizeof(o));
	int fd = open("test.dat",  O_RDWR | O_CREAT, 0666);
	write(fd, &o, sizeof(o));
}

void	load(t_engine *o)
{
	printf("load: %li\n", sizeof(o));
	int fd = open("test.dat",  O_RDWR);
	read(fd, o, sizeof(*o));
}
