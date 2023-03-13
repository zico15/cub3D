/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:20:00 by nprimo            #+#    #+#             */
/*   Updated: 2023/03/13 20:31:12 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>

void	__render_2d(t_buffer *b)
{
	// int	x;
	// int	y;
	// int	grid;

	//y = -1;
	//printf("gw: %i gh: %i\n",map()->grid_width ,  map()->grid_height);
	b->image_resize(map()->sprite,  win()->w, win()->h);
	// if (65 < 33)
	// 	grid = win()->w / (65);
	// else
	// 	grid = win()->h / 33;
	// while (map()->maps[++y])
	// {
	// 	x = -1;
	// 	while (map()->maps[y][++x])
	// 	{
	// 		if (map()->maps[y][x] == '1')
	// 			b->rectangle(vector(x * grid, y * grid, grid, grid), 0x4EC5F1);
	// 		else if (map()->maps[y][x] == 'D')
	// 			b->rectangle(vector(x * grid, y * grid, grid, grid), 0xff0000);
	// 		else if (map()->maps[y][x] == 2)
	// 			b->rectangle(vector(x * grid, y * grid, grid, grid), 0xfffb16);
	// 		else
	// 			b->rectangle(vector(x * grid, y * grid, grid, grid), 0x20272F);
	// 	}
	// }
	// b->rectangle(vector((scene()->player->vector.x * grid) - 3, 
	// (scene()->player->vector.y * grid) - 3, 6, 6), 0x3Ef5F1);
}
