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

static t_scene	*__add_scene(t_scene *scene)
{
	array(engine()->scenes)->add(scene);
	return (scene);
}

int	game_loop(t_engine *e)
{
	if (scene())
		scene()->update();
	return (e != 0);
}

t_engine	*cread_engine(char *title, char *path, int width, int height)
{
	static t_engine	e;

	fthis()->engine = &e;
	e.mlx = mlx_init();
	e.index_scene = 0;
	e.scenes = new_array();
	array(e.scenes)->destroy_element = __destroy_element_object;
	e.add_scene = __add_scene;
	e.load_maps = __load_maps;
	e.close = __close;
	e.set_scene = __set_scene;
	e.win = mlx_new_window(e.mlx,  width, height, title);
	mlx_key_hook(e.win, __funct_key, &e);
	mlx_loop_hook(e.mlx, game_loop, &e);
	return (&e);
}
