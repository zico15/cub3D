/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:57:49 by ezequeil          #+#    #+#             */
/*   Updated: 2022/07/07 21:47:33 by ezequeil         ###   ########.fr       */
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

	max = 100;
	x = p->vector.x + (32 / 2);
	y = p->vector.y + (32 / 2);
	val = PI / 180;
	delta = vector_zero();
	delta.w = GRID_SIZE;
	delta.h = GRID_SIZE;
	i = -1;
	while (++i < max)
	{
		delta.y = y - (i * cos((p->vector.angle + rel_angle) * val));
		delta.x = x + (i * sin((p->vector.angle + rel_angle) * val));
		if (colison().pixel(p, delta.x, delta.y))
			return ;
		(render()).pixel_put_win(delta.x, delta.y, 0x00990099);
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
