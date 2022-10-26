/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/26 18:03:04 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_engine_util.h>

void	__destroy_element_sprite(t_element	*e);
void	init_list_objects_functions(void);
void	__destroy_element_scene(t_element	*e);

static int	__close(char *msg)
{
	engine()->is_game = 0;
	fthis()->player = NULL;
	array(engine()->scenes)->destroy();
	hashmap(engine()->images)->destroy();
	if (canva()->buffer)
		mlx_destroy_image(engine()->mlx, canva()->buffer);
	mlx_destroy_window(engine()->mlx, engine()->win);
	mlx_destroy_display(engine()->mlx);
	free_ob(engine()->mlx);
	printf("========================================\n");
	printf("DESTROY: ENGINE\n");
	printf("MSG: %s\n", msg);
	printf("========================================\n");
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
	if (!engine()->is_game || !scene())
		return (0);
	__funct_mousse_engine(0, 0);
	if (e->is_key_press)
		funct_key_engine(e->keys, EVENT_PRESS);
	scene_remove_objects_list();
	scene()->update();
	scene()->render(e->canva);
	mlx_put_image_to_window(e->mlx, e->win, e->canva->buffer \
	, 0, 0);
	time2 = now();
	e->delta = (time2 - time1) / 1000.0;
	return (0);
}

t_engine	*cread_engine(char *title)
{
	static t_engine	e;

	fthis()->engine = &e;
	e.mlx = mlx_init();
	init_list_objects_functions();
	e.index_scene = 0;
	e.scenes = new_array();
	array(e.scenes)->destroy_element = __destroy_element_scene;
	e.add_scene = __add_scene;
	e.load_maps = __load_maps;
	e.close = __close;
	e.set_scene = __set_scene;
	e.load_img = __load_img;
	e.canva = __canva();
	e.images = new_hashmap();
	array(hashmap(e.images)->list)->destroy_element = __destroy_element_sprite;
	e.load_sprite = __load_sprite;
	e.win = mlx_new_window(e.mlx, win()->w, win()->h, title);
	mlx_hook(e.win, 2, (1L << 0), __funct_key_press, NULL);
	mlx_hook(e.win, 3, (1L << 1), __funct_key_release, NULL);
	mlx_mouse_hook(e.win, __funct_mousse_engine, &e);
	mlx_loop_hook(e.mlx, game_loop, &e);
	return (&e);
}
