/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2023/04/17 20:00:19 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_scene_util.h>

void	__funct_mouse_scene(int x, int y, int event)
{
	t_element	*e;
	t_object	*ob;
	t_object	*this_ob;

	if (array(scene()->mouse_list)->size <= 0)
		return ;
	this_ob = fthis()->object;
	e = array(scene()->mouse_list)->begin;
	while (e)
	{
		ob = (t_object *) e->value;
		fthis()->object = ob;
		ob->funct_mouse(x, y, event);
		e = e->next;
	}
	fthis()->object = this_ob;
}

void	__funct_key_scene(char *key, int type_event)
{
	t_element	*e;
	t_object	*ob;
	t_object	*this_ob;

	if (array(scene()->key_list)->size <= 0)
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
	scene->remove_object_list = new_array();
	array(scene->free_objects)->is_value_destroy = 0;
	array(scene->key_list)->is_value_destroy = 0;
	array(scene->mouse_list)->is_value_destroy = 0;
	array(scene->updade_list)->is_value_destroy = 0;
	array(scene->render_list)->is_value_destroy = 0;
	array(scene->colliders_list)->is_value_destroy = 0;
	array(scene->remove_object_list)->is_value_destroy = 0;
	array(scene->objects)->destroy_element = __destroy_element_object;
}

void	__destroy_scene(void)
{
	t_array		*this;

	this = fthis()->array;
	array(scene()->free_objects)->destroy();
	array(scene()->key_list)->destroy();
	array(scene()->mouse_list)->destroy();
	array(scene()->updade_list)->destroy();
	array(scene()->render_list)->destroy();
	array(scene()->colliders_list)->destroy();
	array(scene()->remove_object_list)->destroy();
	array(scene()->objects)->destroy();
	array(this);
}

void	scene_remove_objects_list(void)
{
	t_object	*ob;

	while (array(scene()->remove_object_list)->size > 0)
	{
		ob = array(scene()->remove_object_list)->get(0);
		if (ob->funct_key)
			array(scene()->key_list)->remove_value(ob);
		if (ob->funct_mouse)
			array(scene()->mouse_list)->remove_value(ob);
		if (ob->update)
			array(scene()->updade_list)->remove_value(ob);
		if (ob->render)
			array(scene()->render_list)->remove_value(ob);
		if (ob->type != PLAYER && ob->type != WALL && ob->type != DOOR)
			array(scene()->free_objects)->remove_value(ob);
		if (map()->maps_ob[(int) ob->vector.y][(int) ob->vector.x] == ob)
			map()->maps_ob[(int) ob->vector.y][(int) ob->vector.x] = NULL;
		printf("remove_objectr\n");
		array(scene()->remove_object_list)->remove_index(0);
	}
}

