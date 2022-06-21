/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 03:01:53 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/21 01:31:40 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

static void	load_map(t_element *e, t_scene *scene)
{
	static int	i;
	char		*str;

	if (!array(scene->map)->size)
		i = 0;
	str = e->value;
	if (string().contains(str, "1") || string().contains(str, "0") \
	|| string().contains(str, "2") || string().contains(str, "N"))
	{
		array(scene->map)->add(string().copy(str));
		i = 0;
	}
	else
		i++;
	if (0 && array(scene->map)->size > 0 && i)
		engine()->close("Error map");
}

void	check_color(t_element *e, void *o)
{
	t_scene	*scene;

	scene = (t_scene *) o;
	if (scene && scene->c && scene->f)
		load_map(e, scene);
	if (string().equals_n(e->value, "F ", 2))
	{
		if (scene->f)
			engine()->close("Error");
		scene->f = string().copy(e->value);
		printf("F: %s", scene->f);
	}
	if (string().equals_n(e->value, "C ", 2))
	{
		if (scene->c)
			engine()->close("Error");
		scene->c = string().copy(e->value);
		printf("C: %s", scene->c);
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

void	check_map(t_scene	*scene, int x, int y)
{
	char	buff[BUFFER_SIZE];
	char	**map;
	int		i;

	map = (char **) array(scene->map)->to_str();
	while (map && map[++y])
	{
		x = -1;
		i = 0;
		while (map[y] && map[y][++x])
		{
			scene->check[y][x] = 0;
			if (map[y][x] == '\t')
				i = cread_space(buff, i);
			else
				buff[i++] = map[y][x];
			if (map[y][x] == 'N')
				scene->player = vector(x, y, 0, 0);
		}
		free_ob(map[y]);
		buff[i] = 0 * (printf("%s", map[y]));
		scene->vector.w = string().size(buff) * 32;
		map[y] = string().copy(buff);
	}
	scene->maps = map;
	scene->vector.h = y * 32;
}
