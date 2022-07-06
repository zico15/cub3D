/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/06 18:37:56 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

t_scene	*__set_scene(int index_scene)
{
	t_scene	*s;

	s = (t_scene *) array(engine()->scenes)->get(index_scene);
	fthis()->scene = s;
	engine()->index_scene = index_scene;
	mlx_clear_window(engine()->mlx, engine()->win);
	return (s);
}

t_scene	*__load_maps(char **args, int size)
{
	t_scene		*scene;
	t_map		*map;
	void		*o;
	int			i;

	i = 0;
	while (++i < size)
	{
		scene = engine()->add_scene(new_scene());
		map = (t_map *) scene->add(new_map());
		map->load(args[i]);
	}
	o = array(engine()->scenes)->get(0);
	if (!o)
		return (NULL);
	scene = (t_scene *) o;
	fthis()->scene = scene;
	return (scene);
}

void	*__load_img(t_object *ob, char *file_name)
{
	void	*img;
	int		h;
	int		w;

	img = mlx_xpm_file_to_image(engine()->mlx, file_name, \
	&w, &h);
	ob->vector.w = w;
	ob->vector.h = h;
	return (img);
}
