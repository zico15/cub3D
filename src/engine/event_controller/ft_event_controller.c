/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <ede-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:08:19 by ezequeil          #+#    #+#             */
/*   Updated: 2023/03/12 16:10:11 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

int	funct_key_engine(char *key, int event)
{
	int				i;

	if (scene())
		(scene()->funct_key)(key, event);
	if (event == EVENT_CLICK && (key[65451] || key[65453]))
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

int	__funct_mousse_move(int x, int y, void *vars)
{
	(void) vars;
	engine()->is_mouse_press = 0;
	if (scene())
		(scene()->funct_mouse)(x, y, 0);
	return (0);
}

int	__funct_mousse_engine(int keycode, void *vars)
{
	int	x;
	int	y;

	(void) vars;
	engine()->is_mouse_press = keycode;
	mlx_mouse_get_pos(engine()->mlx, engine()->win, &x, &y);
	if (scene())
		(scene()->funct_mouse)(x, y, keycode);
	return (0);
}

int	__funct_key_press(int key, void *o)
{
	(void) o;
	if (key == KEY_ESC)
		engine()->close("ESC");
	engine()->keys[key] = 1;
	engine()->is_key_press++;
	funct_key_engine(engine()->keys, EVENT_CLICK);
	return (0);
}

int	__funct_key_release(int key, void *o)
{
	(void) o;
	engine()->is_key_press--;
	engine()->keys[key] = 0;
	funct_key_engine(engine()->keys, EVENT_RELEASE);
	return (0);
}
