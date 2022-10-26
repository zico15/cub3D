/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:03:31 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/26 15:23:52 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_check.h>

int	check_borde(t_map *m, int x, int y);

static int	check_case(t_map *map, int x, int y)
{
	char	c;
	int		size;

	size = string().size(map->check_maps[y]);
	if (y < 0 || y >= map->size_height)
		return (0);
	if (x < 0 || x >= size)
		return (0);
	c = map->check_maps[y][x];
	if (!check_borde(map, x, y))
	{
		map->is_map_ok = 0;
		return (0);
	}
	if (c != '0' && !engine()->new_obs[(int) c])
	{
		map->is_map_ok = 0;
		return (0);
	}
	if (map->check_maps[y][x] == '1')
		return (0);
	map->check_maps[y][x] = '1';
	return ((c != '1'));
}

void	expand(t_map *map, int x, int y)
{
	if (map->is_map_ok && check_case(map, x + 1, y))
		expand(map, x + 1, y);
	if (map->is_map_ok && check_case(map, x - 1, y))
		expand(map, x - 1, y);
	if (map->is_map_ok && check_case(map, x, y + 1))
		expand(map, x, y + 1);
	if (map->is_map_ok && check_case(map, x, y - 1))
		expand(map, x, y - 1);
}

static int	chech_case_map(t_map *map)
{
	int		x;
	int		y;
	char	c;

	y = -1;
	if (!map->is_map_ok)
		return (map->is_map_ok);
	while (map->check_maps[++y])
	{
		x = -1;
		while (map->check_maps[y][++x])
		{
			c = map->check_maps[y][x];
			if (!string().is_space(c) && c != '0' &&!engine()->new_obs[(int) c])
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


int	check_maps_nodes(t_map *map, char **temp, int x, int y)
{
	map->is_map_ok = 0;
	map->check_maps = string().copy_list((const char **) temp);
	map->maps = string().copy_list((const char **) temp);
	map->size_height = string().size_list(map->maps);
	while (map->check_maps[++y])
	{
		x = -1;
		while (map->check_maps[y][++x])
		{
			if ((string().contains)("NSWE", _str(map->check_maps[y][x])))
			{
				map->is_map_ok = check_borde(map, x, y);
				map->is_map_ok = check_pos_init(map, x, y);
				map->player = vector(x, y, 1, 1);
				map->check_maps[y][x] = '1';
				expand(map, x, y);
				break ;
			}
		}
	}
	if (map->count_player != 1)
		map->is_map_ok = 0;
	map->size_height = y;
	return (chech_case_map(map));
}
