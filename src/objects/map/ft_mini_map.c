/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:00:43 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/25 14:38:28 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_check.h>

static int	get_color(t_map *m, t_vector v)
{
	int	x;
	int	y;

	x = (int) v.x;
	y = (int) v.y;
	if (m->maps[y][x] == '1')
		return (0x949e9e);
	if (0 && m->maps[y][x] == ' ')
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
	t_vector	img;

	v = m->vector;
	v.w = m->size_width * GRID_MIN_SIZE;
	v.h = m->size_height * GRID_MIN_SIZE;
	m->sprite = new_sprite((int) v.w + 400, (int) v.h + 400);
	(image()).rectangle(m->sprite->img, m->sprite->v, 0xe5e6e6);
	m->vector_mini_map = vector(0, 0, v.w + 400, v.h + 400);
	img.w = GRID_MIN_SIZE;
	img.h = GRID_MIN_SIZE;
	while (v.y < m->size_height)
	{
		v.x = 0;
		while (v.x < m->size_width)
		{
			img.x = (v.x * GRID_MIN_SIZE) + 200;
			img.y = (v.y * GRID_MIN_SIZE) + 200;
			_printf_rectangle(m, img, v);
			v.x++;
		}
		v.y ++;
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
