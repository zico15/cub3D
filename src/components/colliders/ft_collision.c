/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:21:02 by ezequeil          #+#    #+#             */
/*   Updated: 2022/10/14 18:39:15 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

t_object		*__rectangula_ob(t_object *object, double px, double py);

static t_object	*__collision_ob(t_object *object, double x, double y);
static int		__circular_collision(t_vector a, t_vector b);
static int		__rectangular_collision(t_vector a, t_vector b);
static t_object	*__pixel_collision(t_object *object, double px, double py);

t_collision	collision(void)
{
	static t_collision	c = {__collision_ob, __circular_collision, \
	__rectangular_collision, __pixel_collision, __rectangula_ob
	};

	return (c);
}

static t_object	*__collision_ob(t_object *object, double x, double y)
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
		if (o != object && (collision().rectangular(o->vector, v)))
		{
			object->collision(o);
			o->collision(object);
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
	if (distance < a.distance + b.distance)
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

static t_object	*__pixel_collision(t_object *object, double px, double py)
{
	t_element	*e;
	t_object	*o;
	t_vector	v;

	if (!array(scene()->colliders_list)->size)
		return (0);
	e = array(scene()->colliders_list)->begin;
	v = vector(px, py, 1, 1);
	v.distance = 1;
	while (e)
	{
		o = e->value;
		if (object != o && collision().rectangular(o->vector, v))
			return (o);
		e = e->next;
	}
	return (NULL);
}
