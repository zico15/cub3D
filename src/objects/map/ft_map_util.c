/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:00:43 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/01 23:20:00 by ezequeil         ###   ########.fr       */
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

void	print_check_map(t_map *m)
{
	t_vector	v;
	char		b[3];
	int			dir;

	v = m->vector;
	b[2] = 0;
	dir = 0;
	while (v.y < v.h)
	{
		v.x = 0;
		while (v.x < v.w)
		{
			if (m->dir == 0)
				dir = v.x / 32;
			else if (m->dir == 1)
				dir = v.y / 32;
			else if (m->dir == 2)
				dir = m->check[v.y / 32][v.x / 32] == 1;
			b[0] = ('0' + dir / 10);
			b[1] = ('0' + (dir % 10));
			if ((m->dir != 2 || dir) && m->maps[v.y / 32][v.x / 32] \
			!= '1' && m->maps[v.y / 32][v.x / 32] != ' ')
				mlx_string_put(engine()->mlx, engine()->win, v.x + 5, v.y + 5, \
				0x111111, b);
			v.x += 32;
		}
		v.y += 32;
	}
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

