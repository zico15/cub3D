/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/19 15:53:50 by edos-san         ###   ########.fr       */
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

static void	__load_scene(char *patch)
{
	int			fd;
	void		*file;
	t_element	*e;

	fd = open(patch, O_RDONLY);
	if (fd == -1)
		engine()->close("Error");
	file = new_array();
	while (array(file)->add(get_next_line(fd)))
		;
	printf("file size: %i\n", array(file)->size);
	e = array(engine()->scenes)->add(new_scene(file));
	if (e)
	{
		fthis()->scene = (t_scene *) e->value;
		e->destroy = __destroy_element_object;
	}
	array(file)->destroy();
}

void	__update(t_element *e, void *o)
{
	t_scene		*s;

	s = (t_scene *) e->value;
	s->update();
	array(o);
}

int	game_loop(t_engine *e)
{
	//system("clear");
	//printf("scene: %i\r", array(e->scenes)->size);
	(array(engine()->scenes))->for_each(__update, engine()->scenes);
	return (e != 0);
}

t_engine	*cread_engine(char *title, int width, int height)
{
	static t_engine	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, width, height, title);
	mlx_key_hook(e.win, __funct_key, &e);
	e.scenes = new_array();
	e.load_scene = __load_scene;
	e.close = __close;
	e.print = __print;
	mlx_loop_hook(e.mlx, game_loop, &e);
	fthis()->engine = &e;
	return (&e);
}
