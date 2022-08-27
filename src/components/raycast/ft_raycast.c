/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:57:49 by ezequeil          #+#    #+#             */
/*   Updated: 2022/08/27 20:34:43 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>

double ft_cos(double angle)
{
	double	val;

	val = M_PI / 180;
	return (cos(angle * val));
}

double ft_sin(double angle)
{
	double	val;

	val = M_PI / 180;
	return (sin(angle * val));
}

void	update_print_ray(t_vector p, double rel_angle, void *ray_return, int max)
{
	double		val;
	double		x;
	double		y;
	t_vector	delta;
	double		i;

	x = p.x;
	y = p.y;
	delta = vector_zero();
	delta.w = p.w;
	delta.h = p.h;
	delta.angle = rel_angle;
	i = -1; // delta_ver to check for collisions on vertical lines
	// delta_hor to check for collisions on horizontal lines
	while (++i < max)
	{
		delta.y = y - (i * ft_cos(p.angle + rel_angle));
		delta.x = x + (i * ft_sin(p.angle + rel_angle));
		if (delta.x < 0 || delta.y < 0 || delta.x >= \
		engine()->width || delta.y >= engine()->height)
			return ;
		if (colison().pixel(scene()->player, delta.x, delta.y))
		{
			array(ray_return)->add(copy_vector(&delta));
			return ;
		}
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


double ft_tan(double angle)
{
	double	val;

	val = M_PI / 180;
	return (tan(angle * val));
}

void	raycast(t_player *p, double rel_angle)
{
	t_vector	delta;
	t_vector	step;
	double		angle;
	t_vector	map_pos;
	int			max_loop;
	
	max_loop = 0;
	angle = p->vector.angle + rel_angle;
	// horizontal line
	if (angle < 180)
	{
		delta.y = ((int) p->vector.y / GRID_SIZE) * GRID_SIZE - 0.0001;
		delta.x = (p->vector.y - delta.y) / ft_tan(angle) + p->vector.x;
		step.y = -GRID_SIZE;
		step.x = -step.y / ft_tan(angle);
	}
	if (angle > 180)
	{
		delta.y = ((int) p->vector.y / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
		delta.x = (p->vector.y - delta.y) / ft_tan(angle) + p->vector.x;
		step.y = +GRID_SIZE;
		step.x = -step.y / ft_tan(angle);
	}
	if (angle == 180 || angle == 360 || angle == 0)
		max_loop = 100;
	while (max_loop < 100)
	{
		map_pos.x = delta.x / 
		max_loop++;
	}
}
