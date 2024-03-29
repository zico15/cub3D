/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2023/04/17 20:35:02 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

t_scene	*__set_scene(int index_scene)
{
	t_scene	*s;

	if (index_scene >= array(engine()->scenes)->size)
		return (NULL);
	s = (t_scene *) array(engine()->scenes)->get(index_scene);
	fthis()->scene = s;
	fthis()->map = s->map;
	fthis()->player = s->player;
	fthis()->camera = s->camera;
	engine()->index_scene = index_scene;
	mlx_clear_window(engine()->mlx, engine()->win);
	ft_send(engine()->socket, "FD :-1");
	return (s);
}

t_scene	*__load_maps(char **args, int size)
{
	t_scene		*scene;
	t_map		*map;
	int			i;

	i = 0;
	engine()->args = args;
	scene = engine()->add_scene(new_scene());
	scene->add(new_menu_initial());
	while (++i < size)
	{
		fthis()->player = NULL;
		scene = engine()->add_scene(new_scene());
		map = (t_map *) scene->add(new_map());
		scene->add(new_camera());
		fthis()->object = (t_object *) map;
		scene->map = map;
		map->load(args[i]);
		scene->add(new_menu());
		scene->player = fthis()->player;
	}
	scene = __set_scene(0);
	engine()->is_game = 1;
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
	t_element	*e;
	t_sprite	*s;
	int			w;
	int			h;

	e = hashmap(engine()->images)->get_key(file_name);
	if (e)
		return (e->value);
	s = malloc_ob(sizeof(*s));
	s->img = mlx_xpm_file_to_image(engine()->mlx, file_name, \
	&w, &h);
	s->v.w = w;
	s->v.h = h;
	s->data.img = s->img;
	s->data.addr = mlx_get_data_addr(s->data.img, &s->data.bits_per_pixel, \
	&s->data.line_length, &s->data.endian);
	(hashmap(engine()->images))->put(string().copy(file_name), s);

	return (s);
}

void	__destroy_element_sprite(t_element	*e)
{
	t_sprite	*sprite;

	free_ob(e->key);
	sprite = (t_sprite *) e->value;
	destroy_sprite(sprite);
	free_ob(e);
}
