/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2023/04/17 20:00:31 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_scene_util.h>

void	__destroy_scene(void *object);
void	__init_scene(t_scene *scene);
void	__add_client(char *fd, double x, double y);

static void	__update(void)
{
	t_element	*e;
	t_object	*o;

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
	if (ob->collision)
		array(scene()->colliders_list)->add(ob);
	array((fthis()->scene)->objects)->add(o);
	return (ob);
}

static void	__remove_object(t_object *ob)
{
	array(scene()->remove_object_list)->add(ob);
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
	s->destroy = __destroy_scene;
	s->funct_key = __funct_key_scene;
	s->funct_mouse = __funct_mouse_scene;
	s->remove_object = __remove_object;
	s->add_client = __add_client;
	__init_scene(s);
	array(this);
	fthis()->scene = s;
	return (s);
}
