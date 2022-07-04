/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:08:19 by ezequeil          #+#    #+#             */
/*   Updated: 2022/07/03 21:15:47 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

int	__funct_key(int key, void *o)
{
	t_engine		*e;
	int				i;


	if (scene())
		(scene()->funct_key)(key, 1);
	if (key == 65451 || 65453)
	{
		i = engine()->index_scene;
		i += ((key == 65451) - (key == 65453));
		if (i >= 0 && i < array(engine()->scenes)->size)
			engine()->set_scene(i);
	}
	e = o;
	if (key == 53)
		engine()->close("exit");
	return (o != 0);
}

int	__funct_mousse(int keycode, void *vars)
{
	int	x;
	int	y;

	(void) vars;
	mlx_mouse_get_pos(engine()->mlx, engine()->win, &x, &y);
	if (scene())
		(scene()->funct_mouse)(x, y, keycode);
	return (0);
}
