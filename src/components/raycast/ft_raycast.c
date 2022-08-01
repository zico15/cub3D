/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:57:49 by ezequeil          #+#    #+#             */
/*   Updated: 2022/08/01 18:00:54 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>

void	update_print_ray(t_player *p, double rel_angle, void *ray_return)
{
	double		val;
	double		x;
	double		y;
	t_vector	delta;
	int			i;
	int			max;

	max = 500;
	x = p->vector.x + (p->vector.w / 2);
	y = p->vector.y + (p->vector.h / 2);
	val = PI / 180;
	delta = vector_zero();
	delta.w = p->vector.w;
	delta.h = p->vector.h;
	i = -1;
	while (++i < max)
	{
		delta.y = y - (i * cos((p->vector.angle + rel_angle) * val));
		delta.x = x + (i * sin((p->vector.angle + rel_angle) * val));
		if (delta.x < 0 || delta.y < 0 || delta.x >= \
		engine()->width || delta.y >= engine()->height)
			return ;
		if (colison().pixel((t_object *) p, delta.x, delta.y))
		{
			//printf("delta.x: %f delta.y: %f\n", delta.x, delta.y);
			array(ray_return)->add(copy_vector(&delta));
			return ;
		}
		(canva())->pixel(delta.x, delta.y, 0x00990099);
	}
}

void	*print_raycast(t_player *p)
{
	int		rel_angle;
	void	*ray_return;

	ray_return = new_array();
	rel_angle = -VIEW_ANGLE / 2;
	while (rel_angle < VIEW_ANGLE / 2)
	{
		update_print_ray(p, rel_angle, ray_return);
		rel_angle++;
	}
	return (ray_return);
}
