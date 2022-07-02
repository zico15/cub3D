/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/02 00:08:33 by ezequeil         ###   ########.fr       */
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

static void	__destroy(void *object)
{
	t_scene	*scene;
	t_array	*this;
	t_object *o;

	o = (t_object *) object;
	this = fthis()->array;
	scene = (t_scene *) o;
	printf("destroy->scene\n");
	array(scene->objects)->destroy();
	free_ob(scene->key_list);
	array(this);
}

static t_object	*__add(void *o)
{
	t_object *ob;

	if (!o)
		return (NULL);
	ob = (t_object *) o;
	if (ob->funct_key)
		array(scene()->key_list)->add(ob);
	array((fthis()->scene)->objects)->add(o);
	return (ob);
}

static void	__funct_key(int key, int type_event)
{
	t_element	*e;
	t_object	*ob;

	if (array(scene()->key_list) <= 0)
		return ;
	e = array(scene()->key_list)->begin;
	while (e)
	{
		ob = (t_object *) e->value;
		ob->funct_key(key, type_event);
		e = e->next;
	}
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
	s->funct_key = __funct_key;
	s->key_list = new_array();
	array(s->objects)->destroy_element = __destroy_element_object;
	fthis()->scene = s;
	array(this);
	fthis()->scene = s;
	return (s);
}
