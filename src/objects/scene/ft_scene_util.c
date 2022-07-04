/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/03 21:25:13 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_scene_util.h>

void	__funct_mouse_scene(int x, int y, int type_event)
{
	t_element	*e;
	t_object	*ob;

	if (array(scene()->mouse_list) <= 0)
		return ;
	e = array(scene()->mouse_list)->begin;
	while (e)
	{
		ob = (t_object *) e->value;
		ob->funct_mouse(x, y, type_event);
		e = e->next;
	}
}
