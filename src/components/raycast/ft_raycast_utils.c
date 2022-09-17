/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:39:41 by nprimo            #+#    #+#             */
/*   Updated: 2022/09/17 19:14:39 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>

t_ray	init_ray_hor(t_vector p, double angle)
{
	t_ray	ray;

	ray.vertical = 0;
	ray.collision = 0;
	ray.distance = 1e30;
	if (ft_sin(angle) > 0)
	{
		ray.cross.y = ((int) p.y / GRID_SIZE) * GRID_SIZE - 0.0001;
		ray.offset.y = -GRID_SIZE;
	}
	else if (ft_sin(angle) < 0)
	{
		ray.cross.y = ((int) p.y / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
		ray.offset.y = GRID_SIZE;
	}
	if (angle == 180 || angle == 0 || angle == 360)
	{
		ray.collision = 1;
		ray.cross.y = INT_MIN;
	}
	ray.cross.x = (p.y - ray.cross.y) / ft_tan(angle) + p.x;
	ray.offset.x = -ray.offset.y / ft_tan(angle);
	return (ray);
}

t_ray	init_ray_ver(t_vector p, double angle)
{
	t_ray	ray;

	ray.vertical = 1;
	ray.collision = 0;
	ray.distance = 1e30;
	if (ft_cos(angle) < 0)
	{
		ray.cross.x = ((int) p.x / GRID_SIZE) * GRID_SIZE - 0.0001;
		ray.offset.x = -GRID_SIZE;
	}
	else if (ft_cos(angle) > 0)
	{
		ray.cross.x = ((int) p.x / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
		ray.offset.x = GRID_SIZE;
	}
	if (angle == 90 || angle == 270)
	{
		ray.collision = 1;
		ray.cross.x = INT_MIN;
	}
	ray.cross.y = (p.x - ray.cross.x) * ft_tan(angle) + p.y;
	ray.offset.y = -ray.offset.x * ft_tan(angle);
	return (ray);
}

t_vector	get_cross_position(t_vector cross, t_vector offset, int max_loop)
{
	int			loop;
	t_vector	check_pos;
	t_vector	map_dim;

	loop = -1;
	map_dim.x = (int) map()->vector.w / GRID_SIZE;
	map_dim.y = (int) map()->vector.h / GRID_SIZE;
	while (++loop < max_loop)
	{
		check_pos.x = (int)(cross.x / GRID_SIZE);
		check_pos.y = (int)(cross.y / GRID_SIZE);
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
	t_ray		ray;
	double		angle;

	angle = p.angle + rel_anlge;
	ray = init_ray_hor(p, angle);
	// if (ft_sin(angle) > 0.001)
	// {
	// 	cross.y = ((int) p.y / GRID_SIZE) * GRID_SIZE - 0.0001;
	// 	offset.y = -GRID_SIZE;
	// }
	// else if (ft_sin(angle) < -0.001)
	// {
	// 	cross.y = ((int) p.y / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
	// 	offset.y = GRID_SIZE;
	// }
	// if (angle == 180 || angle == 0 || angle == 360)
	// 	cross.y = p.y;
	// cross.x = (p.y - cross.y) / ft_tan(angle) + p.x;
	// offset.x = -offset.y / ft_tan(angle);
	// if (cross.y == p.y)
	// 	max_loop = 0;
	// cross = get_cross_position(cross, offset, max_loop);
	// return (cross);
	if (ray.collision == 1)
		max_loop = 0;
	ray.cross = get_cross_position(ray.cross, ray.offset, max_loop);
	return (ray.cross);
}
	// if (cross.x >= 0 && cross.y >= 0
	// 	&& cross.x < map()->vector.w && cross.y < map()->vector.h)
	// 	canva()->line(p, cross, 0x00ff0000);

t_vector	ray_check_ver(t_vector p, double rel_anlge, int max_loop)
{
	t_vector	cross;
	t_vector	offset;
	t_ray		ray;
	double		angle;

	angle = p.angle + rel_anlge;
	ray = init_ray_ver(p, angle);
	// if (ft_cos(angle) < -0.001)
	// {
	// 	cross.x = ((int) p.x / GRID_SIZE) * GRID_SIZE - 0.0001;
	// 	offset.x = -GRID_SIZE;
	// }
	// else if (ft_cos(angle) > 0.001)
	// {
	// 	cross.x = ((int) p.x / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
	// 	offset.x = GRID_SIZE;
	// }
	// if (angle == 90 || angle == 270)
	// 	cross.x = p.x;
	// cross.y = (p.x - cross.x) * ft_tan(angle) + p.y;
	// offset.y = -offset.x * ft_tan(angle);
	// if (cross.x == p.x)
	// 	max_loop = 0;
	// cross = get_cross_position(cross, offset, max_loop);
	// return (cross);
	if (ray.collision == 1)
		max_loop = 0;
	ray.cross = get_cross_position(ray.cross, ray.offset, max_loop);
	return (ray.cross);
}
	// if (cross.x >= 0 && cross.y >= 0
	// 	&& cross.x < map()->vector.w && cross.y < map()->vector.h)
	// 	canva()->line(p, cross, 0x00ff0000);