/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:08:19 by ezequeil          #+#    #+#             */
/*   Updated: 2022/10/05 18:20:54 by edos-san         ###   ########.fr       */
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

int	__funct_key_Press(int key, void *o)
{
	(void) o;
	//__funct_key_engine(key, 1);
	printf("__funct_key_Press: %i\n", key);
	engine()->keys[key] = 1;
	engine()->is_key_press++;
	return (0);
}

int	__funct_key_Release(int key, void *o)
{
	(void) o;
	printf("__funct_key_Release: %i\n", key);
	engine()->is_key_press--;
	engine()->keys[key] = 0;
	//__funct_key_engine(key, 2);
	return (0);
}
