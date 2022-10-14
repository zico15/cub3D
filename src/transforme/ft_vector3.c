/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:44:15 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/14 19:08:55 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

t_vector	vector(double x, double y, double w, double h)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.w = w;
	v.h = h;
	v.angle = 0;
	return (v);
}

t_vector	vector_zero(void)
{
	t_vector	v;

	v.x = 0;
	v.y = 0;
	v.z = 0;
	v.w = 0;
	v.h = 0;
	v.angle = 0;
	return (v);
}

t_vector	*copy_vector(t_vector *v)
{
	t_vector	*cp_v;

	cp_v = malloc_ob(sizeof(t_vector));
	cp_v->x = v->x;
	cp_v->y = v->y;
	cp_v->w = v->w;
	cp_v->h = v->h;
	cp_v->angle = v->angle;
	return (cp_v);
}

double	get_vectors_distance(t_vector a, t_vector b, double angle)
{
	double	delta_x;
	double	delta_y;

	delta_x = a.x - b.x;
	delta_y = a.y - b.y;
	return (sqrt(delta_x * delta_x + delta_y * delta_y));
}
