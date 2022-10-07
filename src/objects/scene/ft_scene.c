/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/07 19:57:36 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_scene_util.h>

static void	__update(void)
{
	t_element	*e;
	t_object	*o;

	if (!array(scene()->updade_list)->to_str)
		return ;
	e = array(scene()->updade_list)->begin;
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

static void	__render(t_buffer *b)
{
	t_element	*e;
	t_object	*o;

	if (!array(scene()->render_list)->size)
		return ;
	e = array(scene()->render_list)->begin;
	while (e)
	{
		o = e->value;
		if (o)
		{
			fthis()->object = o;
			o->render(b);
		}
		e = e->next;
	}
}

static void	__destroy(void *object)
{
	t_scene		*scene;
	t_array		*this;
	t_object	*o;

	o = (t_object *) object;
	this = fthis()->array;
	scene = (t_scene *) o;
	printf("destroy->scene\n");
	array(scene->key_list)->is_value_destroy = 0;
	array(scene->key_list)->destroy();
	array(scene->mouse_list)->is_value_destroy = 0;
	array(scene->mouse_list)->destroy();
	array(scene->updade_list)->is_value_destroy = 0;
	array(scene->updade_list)->destroy();
	array(scene->render_list)->is_value_destroy = 0;
	array(scene->render_list)->destroy();
	array(scene->colliders_list)->is_value_destroy = 0;
	array(scene->colliders_list)->destroy();
	array(scene->objects)->destroy();
	array(this);
}

static t_object	*__add(void *o)
{
	t_object	*ob;

	if (!o)
		return (NULL);
	ob = (t_object *) o;
	if (ob->funct_key)
		array(scene()->key_list)->add(ob);
	if (ob->funct_mouse)
		array(scene()->mouse_list)->add(ob);
	if (ob->update)
		array(scene()->updade_list)->add(ob);
	if (ob->render)
		array(scene()->render_list)->add(ob);
	if (ob->colison)
		array(scene()->colliders_list)->add(ob);
	array((fthis()->scene)->objects)->add(o);
	return (ob);
}

t_scene	*new_scene(void)
{
	t_scene		*s;
	t_array		*this;

	this = fthis()->array;
	s = new_object_instance(sizeof(t_scene));
	s->type = SCENE;
	s->update = __update;
	s->render = __render;
	s->add = __add;
	s->destroy = __destroy;
	s->objects = new_array();
	s->funct_key = __funct_key_scene;
	s->funct_mouse = __funct_mouse_scene;
	s->mouse_list = new_array();
	s->key_list = new_array();
	s->updade_list = new_array();
	s->render_list = new_array();
	s->colliders_list = new_array();
	array(s->objects)->destroy_element = __destroy_element_object;
	fthis()->scene = s;
	array(this);
	fthis()->scene = s;
	return (s);
}
