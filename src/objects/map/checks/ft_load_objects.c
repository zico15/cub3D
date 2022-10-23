/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:49:58 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/23 21:18:17 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_check.h>

void	destroy_node(t_node	*n)
{
	array(n->nodes)->destroy();
	free_ob(n);
}

static t_object	*init_player(t_player	*p, int x, int y, char c)
{
	p->vector.x = x + 0.5;
	p->vector.y = y + 0.5;
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
	return ((t_object *) p);
}

static t_object	*add_object_scene(double x, double y, char c)
{
	t_object	*obj;

	obj = NULL;
	if (engine()->new_obs[c])
		obj = engine()->new_obs[c]();
	if (!obj)
		return (NULL);
	if (obj->type == PLAYER)
		obj = init_player((t_player *) new_player(), x, y, c);
	else
		obj->vector = vector(x, y, 1, 1);
	scene()->add(obj);
	if (obj->type != PLAYER && obj->type != WALL && obj->type != DOOR)
		array(scene()->free_objects)->add(obj);
	if (obj->type != PLAYER)
		return (obj);
	return (NULL);
}

void	add_object_all_map(t_map *map)
{
	int			x;
	int			y;

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
