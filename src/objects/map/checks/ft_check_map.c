/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:03:31 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/23 21:21:32 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_check.h>

static int	check_case(t_map *map, int x, int y)
{
	char	c;

	if (y < 0 || y >= map->size_height)
		return (0);
	if (x < 0 || x >= string().size(map->check_maps[y]))
		return (0);
	c = map->check_maps[y][x];
	if (c != '0' && !engine()->new_obs[c])
	{
		map->is_map_ok = 0;
		return (0);
	}
	if (map->check_maps[y][x] == '1')
		return (0);
	map->check_maps[y][x] = '1';
	return ((c != '1'));
}

static void	expand(t_map *map, int x, int y)
{
	if (check_case(map, x + 1, y))
		expand(map, x + 1, y);
	if (check_case(map, x - 1, y))
		expand(map, x - 1, y);
	if (check_case(map, x, y + 1))
		expand(map, x, y + 1);
	if (check_case(map, x, y - 1))
		expand(map, x, y - 1);
}

static void	copy_map(t_map *map)
{
	int	y;

	map->check_maps = malloc_ob(sizeof(char *) * (map->size_height));
	y = -1;
	while (map->maps[++y])
		map->check_maps[y] = string().copy(map->maps[y]);
}

static int	chech_case_map(t_map *map)
{
	int		x;
	int		y;
	char	c;

	y = -1;
	while (map->check_maps[++y])
	{
		x = -1;
		while (map->check_maps[y][++x])
		{
			c = map->check_maps[y][x];
			if (!string().is_space(c) && c != '0' &&!engine()->new_obs[c])
			{
				map->is_map_ok = 0;
				break ;
			}
			if (map->size_width < x)
				map->size_width = x;
		}
	}
	free_list((void **) map->check_maps);
	map->check_maps = NULL;
	return (map->is_map_ok);
}

int	check_maps_nodes(t_map *map, int x, int y)
{
	map->is_map_ok = 0;
	map->size_height = string().size_list(map->maps);
	copy_map(map);
	while (map->maps[++y])
	{
		x = -1;
		while (map->maps[y][++x])
		{
			if ((string().contains)("NSWE", _str(map->maps[y][x])))
			{	
				map->is_map_ok = 1;
				map->player = vector(x, y, 1, 1);
				map->check_maps[y][x] = '1';
				expand(map, x, y);
				break ;
			}
		}
	}
	return (chech_case_map(map));
}
