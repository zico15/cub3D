/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:57:49 by ezequeil          #+#    #+#             */
/*   Updated: 2022/08/27 14:10:38 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>

void	update_print_ray(t_vector p, double rel_angle, void *ray_return, int max)
{
	double		val;
	double		x;
	double		y;
	t_vector	delta;
	int			i;

	x = p.x;
	y = p.y;
	val = M_PI / 180;
	delta = vector_zero();
	delta.w = p.w;
	delta.h = p.h;
	delta.angle = rel_angle;
	i = -1;
	while (++i < max)
	{
		delta.y = y - (i * cos((p.angle + rel_angle) * val));
		delta.x = x + (i * sin((p.angle + rel_angle) * val));
		if (delta.x < 0 || delta.y < 0 || delta.x >= \
		engine()->width || delta.y >= engine()->height)
			return ;
		if (colison().pixel(scene()->player, delta.x, delta.y))
		{
			array(ray_return)->add(copy_vector(&delta));
			return ;
		}
		// (canva())->pixel(delta.x, delta.y, 0x00990099);
	}
}

void	*print_raycast(t_player *p)
{
	double		rel_angle;
	void		*ray_return;

	ray_return = new_array();
	rel_angle = (double) -VIEW_ANGLE / 2;
	while (rel_angle < (double) VIEW_ANGLE / 2)
	{
		update_print_ray(p->vector, rel_angle, ray_return, 500);
		rel_angle += (double) VIEW_ANGLE / N_RAYS;
	}
	return (ray_return);
}
