/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:14:54 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/12 17:00:16 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_check.h>


int	check_borde(t_map *m, int x, int y)
{
	char	c;
	int		size_x;
	int		size_y;

	size_x = string().size(m->check_maps[y]) - 1;
	size_y = m->size_height - 1;
	c = m->check_maps[y][x];
	m->count_player += (string().contains("NSWE", _str(c)) > 0);
	if ((x > 0 && x < size_x) && (y > 0 && y < size_y))
		return (1);
	return (c == '1');
}

char	check_case_ini(t_map *map, int x, int y)
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
	return (c);
}

int	check_pos_init(t_map *m, int x, int y)
{
	int	c;

	if (!m->is_map_ok)
		return (0);
	c = (int) check_case_ini(m, x + 1, y);
	if (!c || (c != '0' && !engine()->new_obs[c]))
		return (0);
	c = (int) check_case_ini(m, x - 1, y);
	if (!c || (c != '0' && !engine()->new_obs[c]))
		return (0);
	c = (int) check_case_ini(m, x, y + 1);
	if (!c || (c != '0' && !engine()->new_obs[c]))
		return (0);
	c = (int) check_case_ini(m, x, y - 1);
	if (!c || (c != '0' && !engine()->new_obs[c]))
		return (0);
	return (1);
}
