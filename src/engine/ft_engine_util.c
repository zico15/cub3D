/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/01 23:57:51 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

t_scene	*__set_scene(int index_scene)
{
	t_scene *s;

	s = (t_scene *) array(engine()->scenes)->get(index_scene);
	fthis()->scene = s;
	engine()->index_scene = index_scene;
	mlx_clear_window(engine()->mlx, engine()->win);
	return (s);
}

t_scene	*__load_maps(char **args, int size)
{
	t_scene		*scene;
	void		*o;
	int			i;

	i = 0;
	while (++i < size)
	{
		scene = engine()->add_scene(new_scene());
		scene->add(new_map(args[i]));
	}
	o = array(engine()->scenes)->get(0);
	if (!o)
		return (NULL);
	scene = (t_scene *) o;
	fthis()->scene = scene;
	return (scene);
} 

int	__funct_key(int key, void *o)
{
	t_engine		*e;
	static t_object	*object;
	int				i;


	if (scene())
		scene()->funct_key(key, 1);
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
	if (key == 35 && !object)
	{
		object = new_object();
		object->img = mlx_xpm_file_to_image(e->mlx, "imgs/wall.xpm", \
		&object->vector.w, &object->vector.h);
		scene()->add(object);
	}
	if (object)
	{
		object->vector.x += ((key == 2) - (key == 0)) * 32;
		object->vector.y += ((key == 1) - (key == 13)) * 32;
	}
	if (key == 7)
		e->map->dir = 0;
	if (key == 16)
		e->map->dir = 1;
	if (key == 8)
		e->map->dir = 2;
	return (o != 0);
}
