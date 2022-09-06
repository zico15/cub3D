/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:57:49 by ezequeil          #+#    #+#             */
/*   Updated: 2022/09/06 19:14:51 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>

#define GREEN 0x0000FF00

void	print_column(double distance_hor, int rel_angle)
{
	t_vector	column;
	int			i;

	i = -(rel_angle - VIEW_ANGLE / 2);
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

void update_ray_hor(t_vector p, double rel_anlge, int max_loop)
{
	t_vector	cross;
	t_vector	offset;
	t_vector	check_pos;
	double		angle;
	int			loop;
	
	cross = vector_zero();
	offset = vector_zero();
	loop = -1;
	angle = p.angle + rel_anlge;
	printf("Angle: %f\n", angle);
	cross.x = -(p.y - cross.y) / ft_tan(angle) + p.x;
	if (angle > 180) // is looking down
	{
		cross.y = ((int) p.x / GRID_SIZE) * GRID_SIZE - 0.0001;
		offset.y = +GRID_SIZE;
	}
	if (angle < 180) // is looking up
	{
		cross.y = ((int) p.x / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
		offset.y = -GRID_SIZE;
	}
	offset.x = offset.y / ft_tan(angle);
	if (angle == 180 || angle == 0 || angle == 360)
		loop = max_loop;
	printf("Player pos: %d %d\n", (int) p.x / GRID_SIZE, (int) p.y / GRID_SIZE);
	while(++loop < max_loop)
	{
		check_pos.x = (int) cross.x / GRID_SIZE;
		check_pos.y = (int) cross.y / GRID_SIZE;
		if (check_pos.x > 0 && check_pos.y > 0
			&& map()->maps[(int) check_pos.x, (int) check_pos.y]
			&& map()->maps[(int) check_pos.x, (int) check_pos.y] == '1')
			loop = max_loop;
		else
		{
			cross.x += offset.x;
			cross.y += offset.y;
		}
	}
	printf("loop: %d\n", loop);
	printf("Check pos: %d %d\n", (int) check_pos.x , (int) check_pos.y);
}

void	*print_raycast(t_player *p)
{
	double		rel_angle;
	void		*ray_return;

	ray_return = new_array();
	rel_angle = (double) + VIEW_ANGLE / 2;
	while (rel_angle > (double) - VIEW_ANGLE / 2)
	{
		update_print_ray(p->vector, rel_angle, 500);
		rel_angle--;
		if (rel_angle == 0)
			update_ray_hor(p->vector, rel_angle, 10);
	}
	return (ray_return);
}
