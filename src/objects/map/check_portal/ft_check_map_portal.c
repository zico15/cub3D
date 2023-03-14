/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_portal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:03:31 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/14 12:29:00 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_check.h>

void 		print_test(char **map);

static t_vector close_map(char **map, char open, char close)
{
	int			x;
	int			y;
	t_vector 	pont;

	y = -1;
	pont = vector(-1, -1, -1, -1);
	while (map[++y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			if (map[y][x] == open)
				map[y][x] = close;
			if (pont.x == -1 && pont.y == -1 && map[y][x] == '0')
				pont = vector(x, y, 0, 0);
			x++;
		}
	}
	return (pont);
}

static int check_case(t_map *map, char **temp, int x, int y)
{
	char c;

	(void) map;
	if (x < 0 || y < 0 || !temp[y] || !temp[y][x])
		return (0);
	c = temp[y][x];
	if (c != 1 && c != 2 && c != 3 && !engine()->new_obs[(int) c])
	{	
		map->is_portal = 0;
		close_map(temp, 1, 3);
	}
	if (c == 1 || c == 2 || c == 3|| c == '1' || !engine()->new_obs[(int) c])
		return (0);
	temp[y][x] = 1 + (!map->is_portal * 2);
	print_test(temp);
	return (1);
}

static void	expand(t_map *map, char **temp, int x, int y)
{
	if (check_case(map, temp, x + 1, y))
		expand(map, temp, x + 1, y);
	if (check_case(map, temp, x - 1, y))
		expand(map, temp, x - 1, y);
	if (check_case(map, temp, x, y + 1))
		expand(map, temp, x, y + 1);
	if (check_case(map, temp, x, y - 1))
		expand(map, temp, x, y - 1);
}

int	check_maps_portal(t_map *map, char **temp, int x, int y)
{
	t_vector pont;

	print_test(temp);
	if (x < 0 && y < 0)
	{	
		return (0);
	}
	temp[y][x] = 1;
	map->is_portal = 1;
	expand(map, temp, x, y);
	if (map->is_portal)
		pont = close_map(temp, 1, 2);
	else
		pont = close_map(temp, 1, 3);
	return (check_maps_portal(map, temp, pont.x, pont.y));
}
