/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/19 11:33:26 by edos-san         ###   ########.fr       */
=======
/*   Updated: 2022/06/19 03:13:50 by edos-san         ###   ########.fr       */
>>>>>>> ezequiel
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

static int	__close(char *msg)
{
	printf("%s\n", msg);
	exit(0);
	return (0);
}

static void	__load_scene(char *patch)
{
	int			fd;
	void		*file;

	fd = open(patch, O_RDONLY);
	if (fd == -1)
		engine()->close("Error");
	file = new_array();
	while (array(file)->add(get_next_line(fd)))
		;
	printf("file size: %i\n", array(file)->size);
	engine()->scene = new_scene(file);
}

static int	game_loop(t_engine *e)
{
	//system("clear");
	printf("scene: %i\r", e->scene != 0);
	return (e != 0);
}



t_engine	*cread_engine(char *title, int width, int height)
{
	static t_engine	e = {0, 0, 0, __load_scene, __close};

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, width, height, title);
	mlx_loop_hook(e.mlx, game_loop, &e);
<<<<<<< HEAD
	fthis()->engine = &e;
=======
	this()->engine = &e;
>>>>>>> ezequiel
	return (&e);
}
