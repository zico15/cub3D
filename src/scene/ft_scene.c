/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/19 15:05:52 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scene_util.h>

static int	__update(void)
{
	t_element	*e;
	t_object	*o;

	e = array(fthis()->scene->objects)->begin;
	while (e)
	{
		o = e->value;
		if (o)
		{
			fthis()->object = o;
			o->update();
		}
		e = e->next;
	}
	return (1);
}

static int	__destroy(t_object *o)
{
	t_scene	*scene;
	t_array	*this;

	this = fthis()->array;
	scene = (t_scene *) o;
	free_ob(scene->c);
	free_ob(scene->f);
	printf("destroy->scene\n");
	array(scene->objects)->destroy();
	array(this);
	return (o != 0);
}

static t_object	*__add(t_object *o)
{
	t_element	*e;

	e = array((fthis()->scene)->objects)->add(o);
	if (e)
		e->destroy = __destroy_element_object;
	return (o);
}

t_scene	*new_scene(void *file)
{
	t_scene		*s;
	t_array		*this;

	this = fthis()->array;
	s = malloc_ob(sizeof(t_scene));
	s->img = 0;
	s->update = __update;
	s->add = __add;
	s->destroy = __destroy;
	s->objects = new_array();
	s->c = 0;
	s->f = 0;
	if (file)
		(array(file))->for_each(check_color, s);
	array(this);
	return (scene(s));
}
