/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:57:49 by ezequeil          #+#    #+#             */
/*   Updated: 2022/09/07 18:15:01 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>

#define GREEN 0x0000FF00
#define D_GREEN 0x00cc00
#define RED	0x00ff0000
#define	D_RED 0x00cc0000

void	print_column(double distance_hor, int pos, int color)
{
	t_vector	column;

	column.h = (W_HEIGHT * 20 / distance_hor);
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

t_vector	ray_check_hor(t_vector p, double rel_anlge, int max_loop)
{
	t_vector	cross;
	t_vector	offset;
	double		angle;
	
	angle = p.angle + rel_anlge;
	if (ft_sin(angle) > 0.001)
	{
		cross.y = ((int) (p.y / GRID_SIZE)) * GRID_SIZE - 0.0001;
		offset.y = -GRID_SIZE;
	}
	else if (ft_sin(angle) < -0.001)
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

t_vector	ray_check_ver(t_vector p, double rel_anlge, int max_loop)
{
	t_vector	cross;
	t_vector	offset;
	double		angle;
	
	angle = p.angle + rel_anlge;
	if (ft_cos(angle) < -0.001)
	{
		cross.x = ((int) (p.x / GRID_SIZE)) * GRID_SIZE - 0.0001;
		offset.x = -GRID_SIZE;
	}
	else if (ft_cos(angle) > 0.001)
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

double *get_distance(t_vector p, double rel_angle)
{
	double		dist_h;
	double		dist_v;
	int			is_v;
	char		wall_face;
	static double	dist[2];

	dist_v = get_vectors_distance(
		ray_check_ver(p, rel_angle, (int) map()->vector.w / GRID_SIZE),
		p, p.angle + rel_angle);
	dist_h = get_vectors_distance(
		ray_check_hor(p, rel_angle, (int) map()->vector.h / GRID_SIZE),
		p, p.angle + rel_angle);
	is_v = 1;
	if (dist_h < dist_v && dist_h > 0)
		dist[0] = dist_h;
	else if (dist_v > 0)
		dist[0] = dist_v;
	else
		dist[0] = dist_h;
	if (dist[0] == dist_h)
		is_v = 0;
	if (ft_cos(p.angle + rel_angle) > 0.001 && is_v == 1)
		dist[1] = 'W';
	if (ft_cos(p.angle + rel_angle) < -0.001 && is_v == 1)
		dist[1] = 'E';
	if (ft_sin(p.angle + rel_angle) > 0.001 && is_v == 0)
		dist[1] = 'S';
	if (ft_sin(p.angle + rel_angle) < -0.001 && is_v == 0)
		dist[1] = 'N';
	return (dist);
}

void	*print_raycast(t_player *p)
{
	double		rel_angle;
	void		*ray_return;
	double		*dist;
	int			color;
	int			i;

	ray_return = new_array();
	rel_angle = VIEW_ANGLE / 2;
	i = 0;
	while (rel_angle > -VIEW_ANGLE / 2)
	{
		color = GREEN;
		dist = get_distance(p->vector, rel_angle);
		if ((char) dist[1] == 'W')
			color = D_GREEN;
		if ((char) dist[1] == 'E')
			color = D_RED;
		if ((char) dist[1] == 'S')
			color = RED;
		print_column(dist[0] * ft_cos(rel_angle), i, color);
		rel_angle -= (double) VIEW_ANGLE / W_WIDTH;
		i++;
	}
	return (ray_return);
}
