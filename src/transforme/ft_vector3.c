/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:44:15 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/01 12:50:55 by edos-san         ###   ########.fr       */
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
	return (cp_v);
}

double	get_vectors_distance(t_vector a, t_vector b)
{
	double	delta_x;
	double	delta_y;

	delta_x = a.x - a.x;
	delta_y = a.y - b.y;
	return (sqrt(delta_x * delta_x + delta_y * delta_y));
}
