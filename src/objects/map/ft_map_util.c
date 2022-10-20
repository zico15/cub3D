/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:00:43 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/14 18:44:49 by nprimo           ###   ########.fr       */
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
		return (0x949e9e);
	if (m->maps[y][x] == ' ')
		return (0xd87041);
	return (0xe5e6e6);
}

static void	_printf_rectangle(t_map *m,	t_vector p, t_vector v)
{
	int	color;

	color = get_color(m, v);
	if (color == 0x949e9e)
	{
		(image()).rectangle(m->sprite->img, p, 0x111313);
		p.x += 1;
		p.y += 1;
		p.w -= 2;
		p.h -= 2;
	}
	(image()).rectangle(m->sprite->img, p, color);
}

void	cread_mini_map(t_map *m)
{
	t_vector	v;

	v = m->vector;
	v.w = (v.w / GRID_SIZE) * GRID_MIN_SIZE;
	v.h = (v.h / GRID_SIZE) * GRID_MIN_SIZE;
	m->sprite = new_sprite((int) v.w + 200, (int) v.h + 200);
	m->vector_mini_map = vector(0, 0, v.w + 200, v.h + 200);
	while (v.y < v.h)
	{
		v.x = 0;
		while (v.x < v.w)
		{
			_printf_rectangle(m, vector(v.x + 50, v.y + 50, \
			GRID_MIN_SIZE, GRID_MIN_SIZE), v);
			v.x += GRID_MIN_SIZE;
		}
		v.y += GRID_MIN_SIZE;
	}
}

t_object	*__get_object_map(int x, int y)
{
	if (x >= 0 && x < map()->size_width && y >= 0 && x < map()->size_height)
		return (map()->maps_ob[y][x]);
	return (NULL);
}

t_map	*map(void)
{
	return (fthis()->map);
}
