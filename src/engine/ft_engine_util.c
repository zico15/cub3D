/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/09 13:04:48 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

t_scene	*__set_scene(int index_scene)
{
	t_scene	*s;

	s = (t_scene *) array(engine()->scenes)->get(index_scene);
	fthis()->scene = s;
	fthis()->map = s->map;
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
		scene->map = map;
		map->load(args[i]);
	}
	o = array(engine()->scenes)->get(0);
	if (!o)
		return (NULL);
	scene = (t_scene *) o;
	fthis()->scene = scene;
	fthis()->map = scene->map;
	return (scene);
}

void	*__load_img(t_vector *v, char *file_name)
{
	void	*img;
	int		h;
	int		w;

	img = mlx_xpm_file_to_image(engine()->mlx, file_name, \
	&w, &h);
	if (!v)
		return (img);
	v->w = w;
	v->h = h;
	return (img);
}
