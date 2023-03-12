/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:20:00 by nprimo            #+#    #+#             */
/*   Updated: 2023/03/12 14:47:52 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>

#define GRID 32

void	__render_2d(t_buffer *b)
{
	int	x;
	int	y;

	y = -1;
	while (map()->maps[++y])
	{
		x = -1;
		while (map()->maps[y][++x])
		{
			if (map()->maps[y][x] == '1')
				b->rectangle(vector(x * GRID, y * GRID, GRID, GRID), 0x4EC5F1);
			else
				b->rectangle(vector(x * GRID, y * GRID, GRID, GRID), 0x20272F);
		}
	}
}
