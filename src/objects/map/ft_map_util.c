/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:00:43 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/31 23:01:31 by edos-san         ###   ########.fr       */
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
	return (0x53eeeb);
}

void	cread_map(t_map *m)
{
	t_vector	v;

	v = m->vector;
	v.w = (v.w / GRID_SIZE) * GRID_MIN_SIZE;
	v.h = (v.h / GRID_SIZE) * GRID_MIN_SIZE;
	m->img = image().new((int) v.w + 100, (int) v.h + 100);
	m->vector_mini_map = vector(0, 0, v.w + 100, v.h + 100);
	while (v.y < v.h)
	{
		v.x = 0;
		while (v.x < v.w)
		{
			image().rectangle(m->img, \
			vector(v.x + 50, v.y + 50, GRID_MIN_SIZE, GRID_MIN_SIZE), \
			get_color(m, v));
			v.x += GRID_MIN_SIZE;
		}
		v.y += GRID_MIN_SIZE;
	}
}

t_map	*map(void)
{
	return (fthis()->map);
}

