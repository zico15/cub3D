/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:00:43 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/17 12:18:01 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_check.h>

static int	get_color(t_map *m, t_vector v)
{
	int	x;
	int	y;

	x = (v.x / GRID_MIN_SIZE);
	y = (v.y / GRID_MIN_SIZE);
	if (m->maps[y][x] == '1')
		return (0x00FF0000);
	if (m->maps[y][x] == '0' || m->maps[y][x] == '2')
		return (0x000000FF);
	if (m->maps[y][x] == 'N')
		return (0x0000FF00);
	if (m->maps[y][x] == 'D')
		return (0x00CC9900);
	return (0x0);
}

void	cread_map(t_map *m)
{
	t_data		data;
	t_vector	v;

	v = m->vector;
	v.w = (v.w / GRID_SIZE) * GRID_MIN_SIZE;
	v.h = (v.h / GRID_SIZE) * GRID_MIN_SIZE;
	data.img = mlx_new_image(engine()->mlx, m->vector.w, m->vector.h);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
	&data.line_length, &data.endian);
	while (v.y < v.h)
	{
		v.x = 0;
		while (v.x < v.w)
		{
			(render()).pixel_put_rec(&data, get_color(m, v), \
			vector(v.x, v.y, GRID_MIN_SIZE, GRID_MIN_SIZE));
			v.x += GRID_MIN_SIZE;
		}
		v.y += GRID_MIN_SIZE;
	}
	m->img = data.img;
}

t_map	*map(void)
{
	return (fthis()->map);
}

