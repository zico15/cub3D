/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 03:01:53 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/02 00:16:53 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_check.h>

static void	load_map(t_element *e, t_map *m)
{
	static int	i;
	char		*str;

	if (!array(m->map)->size)
		i = 0;
	str = e->value;
	if (string().contains(str, "1") || string().contains(str, "0") \
	|| string().contains(str, "2") || string().contains(str, "N"))
	{
		array(m->map)->add(string().copy(str));
		i = 0;
	}
	else
		i++;
	if (0 && array(m->map)->size > 0 && i)
		engine()->close("Error map");
}

void	check_color(t_element *e, void *o)
{
	t_map	*m;

	m = (t_map *) o;
	if (m && m->c && m->f)
		load_map(e, m);
	if (string().equals_n(e->value, "F ", 2))
	{
		if (m->f)
			engine()->close("Error");
		m->f = string().copy(e->value);
	}
	if (string().equals_n(e->value, "C ", 2))
	{
		if (m->c)
			engine()->close("Error");
		m->c = string().copy(e->value);
	}
}

static int	cread_space(char *buff, int i)
{
	buff[i++] = ' ';
	buff[i++] = ' ';
	buff[i++] = ' ';
	buff[i++] = ' ';
	buff[i++] = ' ';
	return (i);
}

static void	clear_check_buff(t_map	*map, char	**maps, int size_h)
{
	int	x;
	int	y;

	y = -1;
	while (++y < 100)
	{
		x = -1;
		while (++x < 100)
			map->check[y][x] = 0;
	}
	map->maps = maps;
	map->vector.h = size_h * 32;
}

void	check_map(t_map	*m, int x, int y)
{
	char	buff[BUFFER_SIZE];
	char	**map;
	int		i;

	map = (char **) array(m->map)->to_str();
	while (map && map[++y])
	{
		x = -1;
		i = 0;
		while (map[y] && map[y][++x])
		{
			m->check[y][x] = 0;
			if (map[y][x] == '\t')
				i = cread_space(buff, i);
			else
				buff[i++] = map[y][x];
			if (map[y][x] == 'N')
				m->player = vector(x, y, 0, 0);
		}
		free_ob(map[y]);
		buff[i] = 0;
		m->vector.w = string().size(buff) * 32;
		map[y] = string().copy(buff);
	}
	generation(m->player, vector(7, 2, 0, 0));
	clear_check_buff(m, map, y);
}
