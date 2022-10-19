/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:49:58 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/18 16:23:05 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_check.h>

void	destroy_node(t_node	*n)
{
	array(n->nodes)->destroy();
	free_ob(n);
}

static t_player	*init_player(t_player	*p, int x, int y, char c)
{
	p->vector.x = x;
	p->vector.y = y;
	if (c == 'N')
	{
		p->dir.y = -1;
		p->plane.x = +0.66;
	}
	else if (c == 'E')
	{
		p->dir.x = 1;
		p->plane.y = +0.66;
	}
	else if (c == 'S')
	{
		p->dir.y = 1;
		p->plane.x = -0.66;
	}
	else if (c == 'W')
	{
	
	}
	(map())->player = vector(x, y, 1, 1);
	return (p);
}

static t_object	*add_object_scene(double x, double y, char c)
{
	t_object	*obj;

	if (c == 'T')
	{	
		obj = new_barrel();
		array(scene()->free_objects)->add(obj);
	}
	else if (c == 'E')
	{	
		obj = new_enemy();
		array(scene()->free_objects)->add(obj);
	}
	else if (c == 'D')
	{	
		obj = new_door();
		array(scene()->free_objects)->add(obj);
	}
	else if (c == '1')
		obj = new_wall();
	else if (string().contains("NSWE", _str(c)))
		obj = (t_object *) init_player(new_player(), x, y, c);
	else
		return (NULL);
	obj->vector = vector(x, y, 1, 1);
	scene()->add(obj);
	if (obj->type == WALL)
		return (obj);
	return (NULL);
}

void	add_object_all_map(t_map *map)
{
	int			x;
	int			y;

	map->size_width = map->vector.w / GRID_SIZE;
	map->size_height = map->vector.h / GRID_SIZE;
	map->grid_width = W_WIDTH / (map->size_width - 2);
	map->grid_height = W_HEIGHT / map->size_height;
	y = 0;
	map->maps_ob = malloc_ob(sizeof(t_object ***) * (map->size_height + 1));
	while (y < map->size_height)
	{
		x = 0;
		map->maps_ob[y] = malloc_ob(sizeof(t_object **)
				* (map->size_width + 1));
		while (x < map->size_width)
		{
			map->maps_ob[y][x] = add_object_scene(x, y, map->maps[y][x]);
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
