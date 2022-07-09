/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colison.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:21:02 by ezequeil          #+#    #+#             */
/*   Updated: 2022/07/09 20:05:50 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

static t_object	*__colison_ob(t_object *object, double x, double y)
{
	t_element	*e;
	t_object	*o;
	t_vector	v;

	if (!array(scene()->colliders_list)->size)
		return (NULL);
	v = object->vector;
	v.x = x;
	v.y = y;
	e = array(scene()->colliders_list)->begin;
	while (e)
	{
		o = e->value;
		if (o != object && (colison().rectangular(o->vector, v)))
		{
			object->colison(o);
			o->colison(object);
			return (o);
		}
		e = e->next;
	}
	return (NULL);
}

static int	__circular_collision(t_vector a, t_vector b)
{
	double	distance;
	double	dx;
	double	dy;

	dx = a.x - b.x;
	dy = a.y - b.y;
	distance = sqrt(dx * dx + dy * dy);
	if (distance < a.radius + b.radius)
		return (1);
	return (0);
}

static int	__rectangular_collision(t_vector a, t_vector b)
{
	if (a.x < b.x + b.w && a.x + a.w > b.x && \
	a.y < b.y + b.h && a.y + a.h > b.y)
		return (1);
	return (0);
}

static int	__pixel_collision(t_object *object, double px, double py)
{
	t_element	*e;
	t_object	*o;
	t_vector	v;

	if (!array(scene()->colliders_list)->size)
		return (0);
	e = array(scene()->colliders_list)->begin;
	v = vector(px, py, 1, 1);
	v.radius = 1;
	while (e)
	{
		o = e->value;
		if (object != o && colison().rectangular(o->vector, v))
			return (1);
		e = e->next;
	}
	return (0);
}

t_colison	colison(void)
{
	static t_colison	c = {__colison_ob, __circular_collision, \
	__rectangular_collision, __pixel_collision
	};

	return (c);
}
