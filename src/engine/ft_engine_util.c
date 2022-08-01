/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/01 12:54:14 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

t_scene	*__set_scene(int index_scene)
{
	t_scene	*s;

	s = (t_scene *) array(engine()->scenes)->get(index_scene);
	fthis()->scene = s;
	fthis()->map = s->map;
	fthis()->player = s->player;
	fthis()->camera = s->camera;
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
		scene->player = fthis()->player;
		scene->add(new_camera());
		scene->add(new_menu());
	}
	scene = __set_scene(0);
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
