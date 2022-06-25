/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/25 15:35:26 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_scene_util.h>

static void	__update(void)
{
	t_element	*e;
	t_object	*o;

	render().print_ob((t_object *)fthis()->scene);
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
}

static void	__destroy(t_object *o)
{
	t_scene	*scene;
	t_array	*this;

	this = fthis()->array;
	scene = (t_scene *) o;
	printf("destroy->scene\n");
	array(scene->objects)->destroy();
	array(this);
}

static t_object	*__add(t_object *o)
{
	t_element	*e;

	e = array((fthis()->scene)->objects)->add(o);
	return (o);
}

t_scene	*new_scene(void)
{
	t_scene		*s;
	t_array		*this;

	this = fthis()->array;
	s = new_object_instance(sizeof(t_scene));
	s->type = SCENE;
	s->update = __update;
	s->add = __add;
	s->destroy = __destroy;
	s->objects = new_array();
	array(s->objects)->destroy_element = __destroy_element_object;
	fthis()->scene = s;
	array(this);
	return (scene(s));
}
