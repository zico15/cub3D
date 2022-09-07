/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:57:49 by ezequeil          #+#    #+#             */
/*   Updated: 2022/09/07 17:53:00 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>

#define GREEN 0x0000FF00

void	print_column(double distance_hor, int pos, int color)
{
	t_vector	column;

	column.h = (int) W_HEIGHT * 10 / distance_hor;
	if (column.h >= W_HEIGHT)
		column.h = W_HEIGHT;
	column.w = 1;
	column.x = pos;
	column.y = W_HEIGHT / 2 - column.h / 2;
	if (column.y < 0)
		column.y = 0;
	if (column.x < 0)
		column.x = 0;
	canva()->rectangle(column, color);
}

// void	update_print_ray(t_vector p, double rel_angle, int max)
// {
// 	t_vector	delta;
// 	double		i;

// 	delta = vector_zero();
// 	delta.w = p.w;
// 	delta.h = p.h;
// 	delta.angle = rel_angle;
// 	i = 0; // first intersection with hor/ver line
// 	while (i < max)
// 	{
// 		delta.y = p.y - (i * ft_sin(p.angle + rel_angle));
// 		delta.x = p.x + (i * ft_cos(p.angle + rel_angle));
// 		if (delta.x < 0 || delta.y < 0 || delta.x >= \
// 			engine()->width || delta.y >= engine()->height)
// 			return ;
// 		if (colison().pixel(scene()->player, delta.x, delta.y))
// 		{
// 			// canva()->pixel(delta.x, delta.y, 0xff0000);
// 			print_column(get_vectors_distance(delta, p, p.angle + rel_angle) * ft_cos(delta.angle), rel_angle);
// 			// canva()->pixel(delta.x, delta.y, 0x00000000);
// 			//printf("Distance: %f\n", get_vectors_distance(delta, p) * ft_cos(delta.angle));
// 			return ;
// 		}
// 		i++; // distance to get to next hor/ver line
// 	}
// }

t_vector	get_cross_position(t_vector cross, t_vector offset, int max_loop)
{
	int			loop;
	t_vector	check_pos;
	t_vector	map_dim;

	loop = -1;
	map_dim.x = (int) map()->vector.w / GRID_SIZE;
	map_dim.y = (int) map()->vector.h / GRID_SIZE;
	while(++loop < max_loop)
	{
		check_pos.x = (int) (cross.x / GRID_SIZE);
		check_pos.y = (int) (cross.y / GRID_SIZE);
		if (check_pos.x >= 0 && check_pos.x < map_dim.x
			&& check_pos.y >= 0 && check_pos.y < map_dim.y
			&& map()->maps[(int) check_pos.y][(int) check_pos.x] == '1')
			loop = max_loop;
		else
		{
			cross.x += offset.x;
			cross.y += offset.y;
		}
	}
	return (cross);
}

t_vector	update_ray_hor(t_vector p, double rel_anlge, int max_loop)
{
	t_vector	cross;
	t_vector	offset;
	double		angle;
	
	angle = p.angle + rel_anlge;
	if (ft_sin(angle) > 0.001) // is looking up
	{
		cross.y = ((int) (p.y / GRID_SIZE)) * GRID_SIZE - 0.0001;
		offset.y = -GRID_SIZE;
	}
	else if (ft_sin(angle) < -0.001) // is looking down
	{
		cross.y = ((int) p.y / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
		offset.y = GRID_SIZE;
	}
	if (angle == 180 || angle == 0 || angle == 360)
		cross.y = p.y;
	cross.x = (p.y - cross.y) / ft_tan(angle) + p.x;
	offset.x = -offset.y / ft_tan(angle);
	if (cross.y == p.y)
		max_loop = 0;
	cross = get_cross_position(cross, offset, max_loop);
	// if (cross.x >= 0 && cross.y >= 0
	// 	&& cross.x < map()->vector.w && cross.y < map()->vector.h)
	// 	canva()->line(p, cross, 0x000000ff);
	return cross;
}

t_vector	update_ray_ver(t_vector p, double rel_anlge, int max_loop)
{
	t_vector	cross;
	t_vector	offset;
	double		angle;
	
	angle = p.angle + rel_anlge;
	if (ft_cos(angle) < -0.001) // is looking left
	{
		cross.x = ((int) (p.x / GRID_SIZE)) * GRID_SIZE - 0.0001;
		offset.x = -GRID_SIZE;
	}
	else if (ft_cos(angle) > 0.001) // is looking right
	{
		cross.x = ((int) p.x / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
		offset.x = GRID_SIZE;
	}
	if (angle == 90 || angle == 270)
		cross.x = p.x;
	cross.y = (p.x - cross.x) * ft_tan(angle) + p.y;
	offset.y = -offset.x * ft_tan(angle);
	if (cross.x == p.x)
		max_loop = 0;
	cross = get_cross_position(cross, offset, max_loop);
	// if (cross.x >= 0 && cross.y >= 0
	// 	&& cross.x < map()->vector.w && cross.y < map()->vector.h)
	// 	canva()->line(p, cross, 0x00ff0000);
	return (cross);
}

double get_distance(t_vector p, double rel_angle)
{
	double		dist_h;
	double		dist_v;
	double		dist;

	dist_v = get_vectors_distance(
		update_ray_ver(p, rel_angle, (int) map()->vector.w / GRID_SIZE),
		p, p.angle + rel_angle);
	dist_h = get_vectors_distance(
		update_ray_hor(p, rel_angle, (int) map()->vector.h / GRID_SIZE),
		p, p.angle + rel_angle);
	if (dist_h < dist_v && dist_h > 0)
		dist = dist_h;
	else if (dist_v > 0)
		dist = dist_v;
	else
		dist = dist_h;
	return (dist);
}

void	*print_raycast(t_player *p)
{
	double		rel_angle;
	void		*ray_return;
	double		dist;
	int			i;

	ray_return = new_array();
	rel_angle = VIEW_ANGLE / 2;
	i = 0;
	while (rel_angle > -VIEW_ANGLE / 2)
	{
		dist = get_distance(p->vector, rel_angle);
		print_column(dist * ft_cos(rel_angle), i, GREEN);
		rel_angle -= (double) VIEW_ANGLE / W_WIDTH;
		i++;
	}
	return (ray_return);
}
