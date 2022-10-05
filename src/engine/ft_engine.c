/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/05 18:27:53 by edos-san         ###   ########.fr       */
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
	double			time1;
	double			time2;

	time1 = now();
	// if (++delay < 7000)
	// 	return (0);
	if (!scene())
		return (0);
	__funct_mousse_engine(0,0);
	if (e->is_key_press)
		funct_key_engine(e->keys, 0);
	scene()->update();
	e->canva->rectangle(vector(0, 0, e->width, e->height / 2), map()->c_color);
	e->canva->rectangle(vector(0, e->height / 2, e->width, e->height / 2), map()->f_color);
	scene()->render(e->canva);
	mlx_put_image_to_window(e->mlx, e->win, e->canva->buffer \
	, 0, 0);
	time2 = now();
	e->delta = (time2 - time1) / 1000.0;
	return (0);
}

void	render_map()
{
	int	y;
	int	x;

	y = -1;
	while (++y < (int) (map()->vector.h / GRID_SIZE))
	{
		x = -1;
		while (++x < (int) (map()->vector.w / GRID_SIZE))
		{
			mlx_string_put(engine()->mlx, engine()->win,
				x * GRID_SIZE + GRID_SIZE / 2,
				y * GRID_SIZE + GRID_SIZE / 2,  0,
				_str(map()->maps[y][x]));
		}
	}
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
	mlx_hook(e.win, 3, (1L << 1), __funct_key_Release, NULL);
	mlx_mouse_hook(e.win, __funct_mousse_engine, &e);
	mlx_loop_hook(e.mlx, game_loop, &e);
	return (&e);
}
