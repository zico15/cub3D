/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2023/04/17 19:46:03 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_engine_util.h>

void		__destroy_element_sprite(t_element	*e);
void		init_list_objects_functions(void);
void		__destroy_element_scene(t_element	*e);
int			__funct_mousse_move(int x, int y, void *vars);
t_sprite	*__new_sprite(int w, int h);
void		_commads(char *data);

static int	__close(char *msg)
{
	engine()->is_game = 0;
	fthis()->player = NULL;
	printf("%s\n", msg);
	array(engine()->scenes)->destroy();
	hashmap(engine()->images)->destroy();
	if (canva()->buffer)
		mlx_destroy_image(engine()->mlx, canva()->buffer);
	mlx_destroy_window(engine()->mlx, engine()->win);
	mlx_destroy_display(engine()->mlx);
	free_ob(engine()->mlx);
	exit(0);
	return (0);
}

static t_scene	*__add_scene(t_scene *scene)
{
	array(engine()->scenes)->add(scene);
	return (scene);
}

void	update_gametime(t_engine *eng)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	eng->world.world_time = 1000000 * current_time.tv_sec + \
	current_time.tv_usec;
	eng->world.delta_time = (eng->world.world_time - \
	eng->world.last_time) / 1000.0;
}

void	show_fps(t_engine *eng)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	if (current_time.tv_sec == eng->world.timer.tv_sec)
		eng->world.fps_counter++;
	else
	{
		//printf("%i\n", eng->world.fps);
		eng->world.fps = eng->world.fps_counter;
		eng->world.fps_counter = 0;
		gettimeofday(&eng->world.timer, NULL);
	}
}

int	game_loop(t_engine *e)
{
	double			time1;
	double			time2;

	time1 = now();
	if (!engine()->is_game || !scene())
		return (0);
	//__funct_mousse_engine(e->is_mouse_press, NULL);
	if (e->is_key_press)
		funct_key_engine(e->keys, EVENT_PRESS);
	scene_remove_objects_list();
	ft_listen(engine()->socket, _commads);
	scene()->update();
	update_gametime(e);
	if (e->world.world_time - e->world.last_time > 50000)
	{
		e->world.last_time = e->world.world_time;
		scene()->render(e->canva);
		show_fps(e);
		mlx_put_image_to_window(e->mlx, e->win, e->canva->buffer \
		, 0, 0);
	}
	time2 = now();
	e->delta = (time2 - time1) / 1000.0;
	e->is_mouse_press = 0;
	return (0);
}

t_engine	*cread_engine(char *title)
{
	static t_engine	e;

	fthis()->engine = &e;
	(void) title;
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
	e.new_sprite = __new_sprite;
	e.canva = __canva();
	e.images = new_hashmap();
	e.clients = new_hashmap();
	e.socket = new_socket("localhost", "1234");
	array(hashmap(e.images)->list)->destroy_element = __destroy_element_sprite;
	e.load_sprite = __load_sprite;
	laod_alfabeto();
	if (MAP_DEBUG)
		return (&e);
	e.win = mlx_new_window(e.mlx, win()->w, win()->h, title);
	mlx_hook(e.win, 2, (1L << 0), __funct_key_press, NULL);
	mlx_hook(e.win, 3, (1L << 1), __funct_key_release, NULL);
	mlx_mouse_hook(e.win, __funct_mousse_engine, &e);
	mlx_hook(e.win, 6, (1L << 6), __funct_mousse_move, NULL);
	mlx_loop_hook(e.mlx, game_loop, &e);
	return (&e);
}
