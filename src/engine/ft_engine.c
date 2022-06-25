/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/25 15:50:12 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_engine_util.h>

static int	__close(char *msg)
{
	printf("%s\n", msg);
	array(engine()->scenes)->destroy();
	mlx_destroy_window(engine()->mlx, engine()->win);
	exit(0);
	return (0);
}

static void	__add_scene(t_scene *scene)
{
	array(engine()->scenes)->add(scene);
}

void	__update(t_element *e, void *o)
{
	t_scene		*s;

	s = (t_scene *) e->value;
	fthis()->scene = s;
	s->update();
	array(o);
}

int	game_loop(t_engine *e)
{
	(array(engine()->scenes))->for_each(__update, engine()->scenes);
	return (e != 0);
}

t_engine	*cread_engine(char *title, char *path, int width, int height)
{
	static t_engine	e;

	fthis()->engine = &e;
	e.mlx = mlx_init();
	e.map = new_map(path);
	e.scenes = new_array();
	array(e.scenes)->destroy_element = __destroy_element_object;
	e.add_scene = __add_scene;
	e.close = __close;
	e.win = mlx_new_window(e.mlx, e.map->vector.w + width, \
	e.map->vector.h + height, title);
	mlx_key_hook(e.win, __funct_key, &e);
	mlx_loop_hook(e.mlx, game_loop, &e);
	return (&e);
}
