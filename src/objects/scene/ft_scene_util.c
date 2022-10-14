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
