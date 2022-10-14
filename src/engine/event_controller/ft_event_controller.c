/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:08:19 by ezequeil          #+#    #+#             */
/*   Updated: 2022/10/14 18:42:33 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

int	funct_key_engine(int *key, int type_event)
{
	int				i;

	if (scene())
		(scene()->funct_key)(key, type_event);
	if (key[65451] || key[65453])
	{
		i = engine()->index_scene;
		i += (key[65451] - key[65453]);
		if (i >= 0 && i < array(engine()->scenes)->size)
			engine()->set_scene(i);
	}
	if (key[53])
		engine()->close("exit");
	return (0);
}

int	__funct_mousse_engine(int keycode, void *vars)
{
	int	x;
	int	y;

	(void) vars;
	mlx_mouse_get_pos(engine()->mlx, engine()->win, &x, &y);
	if (scene())
		(scene()->funct_mouse)(x, y, keycode);
	return (0);
}

int	__funct_key_press(int key, void *o)
{
	(void) o;
	engine()->keys[key] = 1;
	engine()->is_key_press++;
	return (0);
}

int	__funct_key_release(int key, void *o)
{
	(void) o;
	engine()->is_key_press--;
	engine()->keys[key] = 0;
	return (0);
}
