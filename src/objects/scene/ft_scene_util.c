/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/05 18:23:23 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_scene_util.h>

void	__funct_mouse_scene(int x, int y, int type_event)
{
	t_element	*e;
	t_object	*ob;
	t_object	*this_ob;

	if (array(scene()->mouse_list) <= 0)
		return ;
	this_ob = fthis()->object;
	e = array(scene()->mouse_list)->begin;
	while (e)
	{
		ob = (t_object *) e->value;
		fthis()->object = ob;
		ob->funct_mouse(x, y, type_event);
		e = e->next;
	}
	fthis()->object = this_ob;
}

void	__funct_key_scene(int *key, int type_event)
{
	t_element	*e;
	t_object	*ob;
	t_object	*this_ob;

	if (array(scene()->key_list) <= 0)
		return ;
	this_ob = fthis()->object;
	e = array(scene()->key_list)->begin;
	while (e)
	{
		ob = (t_object *) e->value;
		fthis()->object = ob;
		ob->funct_key(key, type_event);
		e = e->next;
	}
	fthis()->object = this_ob;
}

void	__init_scene(t_scene *scene)
{
	scene->free_objects = new_array();
	scene->objects = new_array();
	scene->mouse_list = new_array();
	scene->key_list = new_array();
	scene->updade_list = new_array();
	scene->render_list = new_array();
	scene->colliders_list = new_array();
	array(scene->free_objects)->is_value_destroy = 0;
	array(scene->key_list)->is_value_destroy = 0;
	array(scene->mouse_list)->is_value_destroy = 0;
	array(scene->updade_list)->is_value_destroy = 0;
	array(scene->render_list)->is_value_destroy = 0;
	array(scene->colliders_list)->is_value_destroy = 0;
	array(scene->objects)->destroy_element = __destroy_element_object;
}

void	__destroy_scene(void *object)
{
	t_scene		*scene;
	t_array		*this;
	t_object	*o;

	o = (t_object *) object;
	this = fthis()->array;
	scene = (t_scene *) o;
	printf("destroy->scene\n");
	array(scene->key_list)->destroy();
	array(scene->mouse_list)->destroy();
	array(scene->updade_list)->destroy();
	array(scene->render_list)->destroy();
	array(scene->colliders_list)->destroy();
	array(scene->objects)->destroy();
	array(this);
}
