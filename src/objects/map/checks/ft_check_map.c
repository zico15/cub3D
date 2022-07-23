/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:03:31 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/08 17:59:09 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_check.h>

int	check_case(t_map *map, t_vector v, int check_value)
{
	if ((v.x >= 0 && v.x < v.w) && (v.y >= 0 && v.y < v.h) && \
	map->maps[(int)v.y][(int)v.x] != '1' && !map->check[(int)v.y][(int)v.x])
	{
		if (map->maps[(int)v.y][(int)v.x] == ' ')
		{
			map->check[(int)v.y][(int)v.x] = 0;
			map->is_map_ok = 0;
			return (0);
		}
		map->check[(int)v.y][(int)v.x] = check_value;
		return (1);
	}
	return (0);
}

t_node	*create_node(int x, int y, int v)
{
	t_node	*n;
	t_array	*this;

	this = fthis()->array;
	n = malloc_ob(sizeof(t_node));
	n->x = x;
	n->y = y;
	n->v = v;
	n->nodes = new_array();
	array(n->nodes)->destroy_element = destroy_element_node;
	array(this);
	return (n);
}

static void	expand(t_map *map, t_node *n, int size_w, int size_h)
{
	if (!n)
		return ;
	if (check_case(map, vector(n->x, n->y + 1, size_w, size_h), 1))
		(array(n->nodes))->add(create_node(n->x, n->y + 1, n->v + 1));
	if (check_case(map, vector(n->x + 1, n->y, size_w, size_h), 1))
		(array(n->nodes))->add(create_node(n->x + 1, n->y, n->v + 1));
	if (check_case(map, vector(n->x, n->y - 1, size_w, size_h), 1))
		(array(n->nodes))->add(create_node(n->x, n->y - 1, n->v + 1));
	if (check_case(map, vector(n->x - 1, n->y, size_w, size_h), 1))
		(array(n->nodes))->add(create_node(n->x - 1, n->y, n->v + 1));
}

static void	*satrt_nodes_checks(t_node *n, t_map	*map)
{
	int			i;
	t_array		*this;

	if (!map || !n)
		return (NULL);
	expand(map, n, map->vector.w / GRID_SIZE, map->vector.h / GRID_SIZE);
	this = fthis()->array;
	if (array(n->nodes)->size)
	{
		i = -1;
		while (++i < array(n->nodes)->size)
		{
			satrt_nodes_checks(array(n->nodes)->get(i), map);
			array(this);
		}
		return (map);
	}
	return (NULL);
}

int	check_maps_nodes(t_map *map, t_vector start)
{
	t_node		*n;

	map->is_map_ok = 1;
	n = create_node(start.x / GRID_SIZE, start.y / GRID_SIZE, 0);
	check_case(map, vector(n->x, n->y, map->vector.w / GRID_SIZE, \
	map->vector.h / GRID_SIZE), 1);
	satrt_nodes_checks(n, map);
	destroy_node(n);
	return (map->is_map_ok);
}
