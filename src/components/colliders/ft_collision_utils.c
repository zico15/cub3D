/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collision_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:37:05 by nprimo            #+#    #+#             */
/*   Updated: 2022/10/14 18:38:06 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

t_object	*__rectangula_ob(t_object *object, double px, double py)
{
	t_element	*e;
	t_object	*o;
	t_vector	v;

	if (!array(scene()->colliders_list)->size)
		return (0);
	e = array(scene()->colliders_list)->begin;
	v = vector(px, py, GRID_SIZE, GRID_SIZE);
	while (e)
	{
		o = e->value;
		if (object != o && collision().rectangular(o->vector, v))
			return (o);
		e = e->next;
	}
	return (NULL);
}
