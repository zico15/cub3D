/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/19 16:33:32 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

int	__funct_key(int key, void *o)
{
	t_engine		*e;
	t_scene			*scene;
	static t_object	*object;

	e = o;
	if (key == 53)
		engine()->close("exit");
	if (key == 35 && !object)
	{
		scene = array(e->scenes)->get(0);
		object = new_object();
		object->img = mlx_xpm_file_to_image(e->mlx, "imgs/wall.xpm", \
		&object->width, &object->height);
		scene->add(object);
	}
	if (object)
	{
		object->x += ((key == 2) - (key == 0)) * 32;
		object->y += ((key == 1) - (key == 13)) * 32;
	}
	return (o != 0);
}

void	__print(t_object *o)
{
	//printf("p: %i\n", (o->img != 0));
	if (o && o->img)
		mlx_put_image_to_window(engine()->mlx, engine()->win, \
		o->img, o->x, o->y);
}
