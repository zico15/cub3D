/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/14 18:41:29 by nprimo           ###   ########.fr       */
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
		scene->add(new_camera());
		scene->add(new_menu());
		map = (t_map *) scene->add(new_map());
		scene->map = map;
		map->load(args[i]);
		scene->player = fthis()->player;	
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

t_sprite	*__load_sprite(char *file_name)
{
	t_sprite	*s;
	int			w;
	int			h;

	s = malloc_ob(sizeof(*s));
	s->img = mlx_xpm_file_to_image(engine()->mlx, file_name, \
	&w, &h);
	s->v.w = w;
	s->v.h = h;
	s->data.img = s->img;
	s->data.addr = mlx_get_data_addr(s->data.img, &s->data.bits_per_pixel, \
	&s->data.line_length, &s->data.endian);
	return (s);
}
