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

t_vector	vector_grid_size(t_vector v, double w, double h)
{
	v.x = (v.x * map()->grid_width);
	v.y = (v.y * map()->grid_height);
	v.w = w;
	v.h = h;
	return (v);
}

int	vector_distance(t_vector a, t_vector b)
{
	int		x;
	int		y;

	x = a.x - b.x;
	if (x < 0)
		x *= -1;
	y = a.y - b.y;
	if (y < 0)
		y *= -1;
	return (x + y);
}

t_vector	*new_vector(double x, double y)
{
	t_vector	*tmp;

	tmp = malloc_ob(sizeof(t_vector));
	tmp->x = x;
	tmp->y = y;
	return (tmp);
}
