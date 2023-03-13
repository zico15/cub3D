/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_portal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:03:31 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/13 20:54:43 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_check.h>

void 		print_test(char **map);
t_vector	close_map(char **map, char open, char close);

static int check_case(t_map *map, char **temp, int x, int y)
{
	char c;

	(void) map;
	if (x < 0 || y < 0 || !temp[y] || !temp[y][x] || !map->is_portal)
		return (0);
	c = temp[y][x];
	if (c != 1 && c != 2 && c != 3 && !engine()->new_obs[(int) c])
		map->is_portal = 0;
	if (c == 1 || c == 2 || c == 3|| c == '1' || !engine()->new_obs[(int) c])
		return (0);
	temp[y][x] = 1;
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

void copy_map_portal(t_map *map, char **temp)
{
	int h;
	int	w;
	int s;

	w = 0;
	h = -1;
	while (temp[++h])
	{
		s = string().size(temp[h]);
		if (s > w)
			w = s;
	}
	map->grid_height = h + 1;
	map->grid_width = w + 1;
	map->maps_portal = malloc_ob(sizeof(char *) * h);
	h = -1;
	while (temp[++h])
	{	
		w = -1;
		map->maps_portal[h] = malloc_ob(sizeof(char) * w);
		while (temp[h][++w])
			map->maps_portal[h][w] = temp[h][w];
	}
}

int	check_maps_portal(t_map *map, char **temp, int x, int y)
{
	t_vector pont;

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
