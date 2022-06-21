/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:00:43 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/21 22:26:31 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

static int	get_color(t_scene *scene, int x, int y)
{
	if (scene->maps[y][x] == '1')
		return (0x00FF0000);
	if (scene->maps[y][x] == '0' || scene->maps[y][x] == '2')
		return (0x000000FF);
	if (scene->maps[y][x] == 'N')
		return (0x0000FF00);
	return (0x0);
}

void	print_check_map(t_scene *scene)
{
	t_vector	v;
	char		b[3];
	int			dir;

	v = scene->vector;
	b[2] = 0;
	while (v.y < v.h)
	{
		v.x = 0;
		while (v.x < v.w)
		{
			if (scene->dir == 0)
				dir = v.x / 32;
			else if (scene->dir == 1)
				dir = v.y / 32;
			else if (scene->dir == 2)
				dir = scene->check[v.y / 32][v.x / 32] == 1;
			b[0] = ('0' + dir / 10);
			b[1] = ('0' + dir % 10);
			if ((scene->dir != 2 ||  dir) && scene->maps[v.y / 32][v.x / 32] \
			!= '1' && scene->maps[v.y / 32][v.x / 32] != ' ')
				mlx_string_put(engine()->mlx, engine()->win, v.x + 5, v.y + 5, \
				0x111111, b);
			v.x += 32;
		}
		v.y += 32;
	}
}

void	cread_map(t_scene *scene)
{
	t_data		data;
	t_vector	v;
	int			x;
	int			y;

	data.img = mlx_new_image(engine()->mlx, scene->vector.w, scene->vector.h);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
	&data.line_length, &data.endian);
	v = scene->vector;
	y = 0;
	while (y < v.h)
	{
		x = 0;
		while (x < v.w)
		{
			(render()).pixel_put_rec(&data, get_color(scene, x / 32, y / 32), \
			vector(x, y, 32, 32));
			x += 32;
		}
		y += 32;
	}
	scene->img = data.img;
}

