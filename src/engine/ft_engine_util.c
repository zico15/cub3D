/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/21 02:01:34 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

static void	check_case(t_scene *scene, t_vector v)
{
	if ((v.x >= 0 && v.x < v.w) && (v.y >= 0 && v.y < v.h))
	{
		if (scene->maps[v.y][v.x] != '1')
		{
			scene->check[v.y][v.x] = scene->player.w;
			printf("x: %i y: %i | w: %i h: %i case: %i\n", v.x, v.y, v.w, v.h, scene->check[v.y][v.x]);
		}
	}
}

void	teste(t_scene *scene, int size_w, int size_h)
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;

	scene->player.w += 1;
	scene->player.h += 1;
	x1 = scene->player.x - scene->player.w;
	y1 = scene->player.y - scene->player.h;
	x2 = scene->player.x + scene->player.w;
	y2 = scene->player.y + scene->player.h;
	check_case(scene, vector(x1, y1, size_w, size_h));
	check_case(scene, vector(x2, y1, size_w, size_h));
	check_case(scene, vector(x1, y2, size_w, size_h));
	check_case(scene, vector(x2, y2, size_w, size_h));
	check_case(scene, vector(x1, scene->player.y, size_w, size_h));
	check_case(scene, vector(x2, scene->player.y, size_w, size_h));
	check_case(scene, vector(scene->player.x, y1, size_w, size_h));
	check_case(scene, vector(scene->player.x, y2, size_w, size_h));
}

int	__funct_key(int key, void *o)
{
	t_engine		*e;
	t_scene			*scene;
	static t_object	*object;

	printf("key: %i\n", key);
	e = o;
	scene = array(e->scenes)->get(0);
	if (key == 53)
		engine()->close("exit");
	if (key == 35 && !object)
	{
		object = new_object();
		object->img = mlx_xpm_file_to_image(e->mlx, "imgs/wall.xpm", \
		&object->vector.w, &object->vector.h);
		scene->add(object);
	}
	if (object)
	{
		object->vector.x += ((key == 2) - (key == 0)) * 32;
		object->vector.y += ((key == 1) - (key == 13)) * 32;
	}
	if (key == 7)
		scene->dir = 0;
	if (key == 16)
		scene->dir = 1;
	if (key == 8)
		scene->dir = 2;
	if (key == 76)
		teste(scene, scene->vector.w / 32, scene->vector.h / 32);
	return (o != 0);
}
