/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:57:49 by ezequeil          #+#    #+#             */
/*   Updated: 2022/09/07 18:44:42 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>

#define GREEN 0x0000FF00
#define D_GREEN 0x00cc00
#define RED 0x00ff0000
#define D_RED 0x00cc0000

t_vector	ray_check_hor(t_vector p, double rel_anlge, int max_loop);
t_vector	ray_check_ver(t_vector p, double rel_anlge, int max_loop);

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

char	get_wall_facing_dir(double angle, t_vector dist)
{
	int		is_v;
	char	dir;

	is_v = 1;
	if (dist.x == dist.h)
		is_v = 0;
	if (ft_cos(angle) > 0.001 && is_v == 1)
		dir = 'W';
	if (ft_cos(angle) < -0.001 && is_v == 1)
		dir = 'E';
	if (ft_sin(angle) > 0.001 && is_v == 0)
		dir = 'S';
	if (ft_sin(angle) < -0.001 && is_v == 0)
		dir = 'N';
	return (dir);
}

t_vector	get_distance(t_vector p, double rel_angle)
{
	t_vector	dist;
	int			is_v;

	dist.w = get_vectors_distance(
			ray_check_ver(p, rel_angle, (int) map()->vector.w / GRID_SIZE),
			p, p.angle + rel_angle);
	dist.h = get_vectors_distance(
			ray_check_hor(p, rel_angle, (int) map()->vector.h / GRID_SIZE),
			p, p.angle + rel_angle);
	dist.x = dist.h;
	if (dist.h < dist.w && dist.h > 0)
		dist.x = dist.h;
	else if (dist.w > 0)
		dist.x = dist.w;
	dist.y = get_wall_facing_dir(p.angle + rel_angle, dist);
	return (dist);
}

void	print_raycast(t_player *p)
{
	double		rel_angle;
	t_vector	dist;
	int			color;
	int			i;

	rel_angle = VIEW_ANGLE / 2;
	i = 0;
	while (rel_angle > -VIEW_ANGLE / 2)
	{
		color = GREEN;
		dist = get_distance(p->vector, rel_angle);
		if ((char) dist.y == 'W')
			color = D_GREEN;
		if ((char) dist.y == 'E')
			color = D_RED;
		if ((char) dist.y == 'S')
			color = RED;
		print_column(dist.x * ft_cos(rel_angle), i, color);
		rel_angle -= (double) VIEW_ANGLE / W_WIDTH;
		i++;
	}
}
