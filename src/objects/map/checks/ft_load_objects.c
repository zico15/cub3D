/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:49:58 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/27 15:51:39 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_check.h>

void	cread_mini_map(t_map *m);

t_object	*init_player(t_player	*p, int x, int y, char c)
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
	if (engine()->new_obs[(int) c])
		obj = engine()->new_obs[(int) c]();
	if (!obj)
		return (NULL);
	if (obj->type == PLAYER)
		obj = init_player((t_player *) obj, x, y, c);
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

	y = -1;
	if (map->size_width < 1 || map->size_height < 1 || !map->maps)
		return ;
	map->vector.w = map->size_width * GRID_SIZE;
	map->vector.h = map->size_height * GRID_SIZE;
	map->grid_width = win()->w / (map->size_width - 2);
	map->grid_height = win()->h / map->size_height;
	cread_mini_map(map);
	map->maps_ob = malloc_ob(sizeof(t_object ***) * (map->size_height + 1));
	while (map->maps[++y])
	{
		map->maps_ob[y] = malloc_ob(sizeof(t_object **)
				* (map->size_width + 1));
		x = -1;
		while (map->maps[y][++x])
		{
			map->maps_ob[y][x] = add_object_scene(x, y, map->maps[y][x]);
			if (string().contains("NSWE", _str(map->maps[y][x])))
				map->maps[y][x] = '0';
		}
	}
}

void	destroy_element_node(t_element	*e)
{
	t_node	*n;
	t_array	*this;

	this = fthis()->array;
	n = e->value;
	if (n)
	{
		array(n->nodes)->destroy();
		free_ob(n);
	}
	array(this);
	free_ob(e->key);
}
