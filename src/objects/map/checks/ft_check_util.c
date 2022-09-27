/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:49:58 by edos-san          #+#    #+#             */
/*   Updated: 2022/09/21 17:51:00 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_check.h>

void	destroy_node(t_node	*n)
{
	array(n->nodes)->destroy();
	free_ob(n);
}

void	add_object_scene(double x, double y, char c)
{
	double		angle;
	t_object	*obj;

	angle = 0;
	if (c == 'T')
		obj = scene()->add(new_teste());
	if (c == 'D')
		obj = scene()->add(new_door());
	else if (c == '1')
		obj = scene()->add(new_wall());
	else if (string().contains("NSWE", _str(c)))
	{
		obj = scene()->add(new_player());
		map()->player = vector(x * GRID_SIZE, y * GRID_SIZE, GRID_SIZE, GRID_SIZE);
	}
	else
		return ;
	if (c == 'W')
		angle = 180;
	if (c == 'N')
		angle = 90;
	if (c == 'S')
		angle = -90;
	obj->vector = vector(x * GRID_SIZE, y * GRID_SIZE, GRID_SIZE, GRID_SIZE);
	obj->vector.angle = angle;
	obj->vector.radius = GRID_SIZE;
	if (string().contains("NSWE", _str(c)) || c == 'T')
	{
		obj->vector.w = 10;
		obj->vector.h = 10;
		obj->vector.radius = 15;
	}
}

void	add_object_all_map(t_map *map)
{
	t_vector	v;
	int			x;
	int			y;

	v = map->vector;
	v.w = v.w / GRID_SIZE;
	v.h = v.h / GRID_SIZE;
	y = 0;
	while (y < v.h)
	{
		x = 0;
		while (x < v.w)
		{
			add_object_scene(x, y, map->maps[y][x]);
			if (string().contains("NSWE", _str(map->maps[y][x])))
				map->maps[y][x] = '0';
			x++;
		}
		y++;
	}
}

void	destroy_element_node(t_element	*e)
{
	t_node	*n;
	t_array	*this;

	this = fthis()->array;
	n = e->value;
	if (n)
		destroy_node(n);
	array(this);
	free_ob(e->key);
}
