/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:57:49 by ezequeil          #+#    #+#             */
/*   Updated: 2022/07/31 20:08:31 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>

void	print_ray(t_player *p, double rel_angle)
{
	double		val;
	double		x;
	double		y;
	t_vector	delta;
	int			i;
	int			max;

	max = 99999;
	x = p->vector.x + (GRID_SIZE / 2);
	y = p->vector.y + (GRID_SIZE / 2);
	val = PI / 180;
	delta = vector_zero();
	delta.w = GRID_SIZE;
	delta.h = GRID_SIZE;
	i = -1;
	while (++i < max)
	{
		delta.y = y - (i * cos((p->vector.angle + rel_angle) * val));
		delta.x = x + (i * sin((p->vector.angle + rel_angle) * val));
		if (delta.x < 0 || delta.y < 0 || delta.x >= \
		engine()->width || delta.y >= engine()->height)
			return ;
		if (colison().pixel((t_object *) p, delta.x, delta.y))
			return ;
		(canva())->pixel(delta.x, delta.y, 0x00990099);
	}
}

void	print_raycast(t_player *p)
{
	int		rel_angle;

	rel_angle = -45;
	while (rel_angle < 45)
	{
		print_ray(p, rel_angle);
		rel_angle++;
	}
}
