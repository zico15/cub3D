/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:57:49 by ezequeil          #+#    #+#             */
/*   Updated: 2022/08/28 20:27:57 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>

#define GREEN 0x0000FF00

void	print_column(double distance_hor, int rel_angle)
{
	t_vector	column;
	int			i;

	i = rel_angle + VIEW_ANGLE / 2;
	column.h = (int) W_HEIGHT * 10 / distance_hor;
	if (column.h >= W_HEIGHT)
		column.h = W_HEIGHT;
	column.w = W_WIDTH / VIEW_ANGLE;
	column.x = i * column.w;
	column.y = W_HEIGHT / 2 - column.h / 2;
	if (column.y < 0)
		column.y = 0;
	if (column.x < 0)
		column.x = 0;
	canva()->rectangle(column, GREEN);
}

void	update_print_ray(t_vector p, double rel_angle, int max)
{
	double		val;
	t_vector	delta;
	double		i;

	delta = vector_zero();
	delta.w = p.w;
	delta.h = p.h;
	delta.angle = rel_angle;
	i = 0; // first intersection with hor/ver line
	while (i < max)
	{
		delta.y = p.y - (i * ft_sin(p.angle + rel_angle));
		delta.x = p.x + (i * ft_cos(p.angle + rel_angle));
		if (delta.x < 0 || delta.y < 0 || delta.x >= \
			engine()->width || delta.y >= engine()->height)
			return ;
		if (colison().pixel(scene()->player, delta.x, delta.y))
		{
			// canva()->pixel(delta.x, delta.y, 0xff0000);
			print_column(get_vectors_distance(delta, p) * ft_cos(delta.angle), rel_angle);
			// canva()->pixel(delta.x, delta.y, 0x00000000);
			//printf("Distance: %f\n", get_vectors_distance(delta, p) * ft_cos(delta.angle));
			return ;
		}
		i++; // distance to get to next hor/ver line
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
		update_print_ray(p->vector, rel_angle, 500);
		rel_angle++;
	}
	return (ray_return);
}
