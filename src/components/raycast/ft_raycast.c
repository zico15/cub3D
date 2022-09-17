/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:57:49 by ezequeil          #+#    #+#             */
/*   Updated: 2022/09/17 20:51:08 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>

#define GREEN 0x0000FF00
#define D_GREEN 0x00cc00
#define RED 0x00ff0000
#define D_RED 0x00cc0000

t_ray		get_ray_return(t_vector p, double rel_angle);	

void	print_column(double distance_hor, int pos, int color)
{
	t_vector	column;

	column.h = (W_HEIGHT * 20 / distance_hor);
	if (column.h >= W_HEIGHT)
		column.h = W_HEIGHT;
	column.w = W_WIDTH / N_RAYS;
	column.x = pos * column.w;
	column.y = W_HEIGHT / 2 - column.h / 2;
	if (column.y < 0)
		column.y = 0;
	if (column.x < 0)
		column.x = 0;
	canva()->rectangle(column, color);
}

char	get_ray_face(t_ray ray, double angle)
{
	char	dir;

	if (ft_cos(angle) >= 0 && ray.vertical == 1)
		dir = 'W';
	if (ft_cos(angle) <= 0 && ray.vertical == 1)
		dir = 'E';
	if (ft_sin(angle) >= 0 && ray.vertical == 0)
		dir = 'S';
	if (ft_sin(angle) <= 0 && ray.vertical == 0)
		dir = 'N';
	return (dir);
}

void	render_view(t_player *p)
{
	double		rel_angle;
	t_ray		ray;
	int			color;
	int			i;

	rel_angle = VIEW_ANGLE / 2;
	i = -1;
	while (++i <= N_RAYS)
	{
		color = GREEN;
		ray = get_ray_return(p->vector, rel_angle);
		ray.face = get_ray_face(ray, p->vector.angle + rel_angle);
		if (ray.face == 'W')
			color = D_GREEN;
		if (ray.face == 'E')
			color = D_RED;
		if (ray.face == 'S')
			color = RED;
		print_column(ray.distance * ft_cos(rel_angle), i, color);
		rel_angle -= (double) VIEW_ANGLE / N_RAYS;
	}
}
