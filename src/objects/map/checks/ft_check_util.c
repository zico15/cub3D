/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:49:58 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/09 19:52:40 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_check.h>

void	destroy_node(t_node	*n)
{
	array(n->nodes)->destroy();
	free_ob(n);
}

static void	add_object_scene(double x, double y, char c)
{
	double		angle;
	t_object	*obj;

	angle = 0;
	if (c == 'T')
		obj = scene()->add(new_teste());
	else if (c == '1')
		obj = scene()->add(new_wall());
	else if (string().contains("NSWE", _str(c)))
		obj = scene()->add(new_player());
	else
		return ;
	if (c == 'S')
		angle = 180;
	if (c == 'E')
		angle = 90;
	if (c == 'W')
		angle = -90;
	obj->vector = vector(x * GRID_SIZE, y * GRID_SIZE, GRID_SIZE, GRID_SIZE);
	obj->vector.angle = angle;
	obj->vector.radius = GRID_SIZE;
}

void	add_object_all_map(t_map *map)
{
	t_vector	v;
	int			x;
	int			y;

	v = map->vector;
	v.w = v.w / GRID_SIZE;
	v.h = v.h / GRID_SIZE;
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
