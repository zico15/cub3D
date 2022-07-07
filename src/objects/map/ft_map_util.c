/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:00:43 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/07 17:33:31 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_check.h>

static int	get_color(t_map *m, int x, int y)
{
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
	int			x;
	int			y;

	data.img = mlx_new_image(engine()->mlx, m->vector.w, m->vector.h);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
	&data.line_length, &data.endian);
	v = m->vector;
	y = 0;
	while (y < v.h)
	{
		x = 0;
		while (x < v.w)
		{
			(render()).pixel_put_rec(&data, get_color(m, x / 32, y / 32), \
			vector(x, y, 32, 32));
			x += 32;
		}
		y += 32;
	}
	m->img = data.img;
}

t_map	*map(void)
{
	return (fthis()->map);
}

