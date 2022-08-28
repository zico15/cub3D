/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/28 15:00:49 by nprimo           ###   ########.fr       */
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
	static int	delay;

	if (++delay < 7000)
		return (0);
	delay = 0;
	if (!scene())
		return (0);
	scene()->update();
	e->canva->rectangle(vector(0, 0, e->width, e->height), 0xc4994a);
	scene()->render(e->canva);
	mlx_put_image_to_window(e->mlx, e->win, e->canva->buffer \
	, 0, 0);
	return (0);
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
	e.load_img = __load_img;
	e.width = width;
	e.height = height;
	e.canva = __canva();
	e.load_sprite = __load_sprite;
	e.win = mlx_new_window(e.mlx, width, height, title);
	mlx_hook(e.win, 2, (1L << 0), __funct_key_Press, NULL);
	//mlx_hook(e.win, 3, (1L << 1), __funct_key_Release, NULL);
	mlx_mouse_hook(e.win, __funct_mousse_engine, &e);
	mlx_loop_hook(e.mlx, game_loop, &e);
	return (&e);
}
