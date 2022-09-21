/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:39:41 by nprimo            #+#    #+#             */
/*   Updated: 2022/09/21 19:15:28 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>

t_vector	get_cross_position(t_vector cross, t_vector offset, int max_loop, t_ray	*ray_ver)
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
			&& (map()->maps[(int) check_pos.y][(int) check_pos.x] == '1' || map()->maps[(int) check_pos.y][(int) check_pos.x] == 'D')
			// && map()->maps[(int) check_pos.y][(int) check_pos.x] != '0'
			)
			{
				ray_ver->ob = colison().rectangula_ob(scene()->player, (int)cross.x , (int)cross.y);
				loop = max_loop;
			}
		else
		{
			cross.x += offset.x;
			cross.y += offset.y;
		}
	}
	return (cross);
}

t_ray	init_ray_hor(t_vector p, double angle)
{
	t_ray	ray;

	ray.vertical = 0;
	ray.collision = 0;
	ray.distance = 1e30;
	ray.angle = angle;
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
	ray.angle = angle;
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

t_ray	get_ray_return(t_vector p, double rel_angle)
{
	t_ray	ray_ver;
	t_ray	ray_hor;
	int		max_loop;

	ray_ver = init_ray_ver(p, p.angle + rel_angle);
	ray_ver.cross = get_cross_position(ray_ver.cross, ray_ver.offset, 100, &ray_ver);
	ray_ver.distance = get_vectors_distance(ray_ver.cross,
			p, p.angle + rel_angle);
	ray_hor = init_ray_hor(p, p.angle + rel_angle);
	ray_hor.cross = get_cross_position(ray_hor.cross, ray_hor.offset, 100, &ray_ver);
	ray_hor.distance = get_vectors_distance(p, ray_hor.cross,
			p.angle + rel_angle);
	if (ray_ver.distance < ray_hor.distance)
		return (ray_ver);
	return (ray_hor);
}
