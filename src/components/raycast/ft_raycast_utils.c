/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:39:41 by nprimo            #+#    #+#             */
/*   Updated: 2022/09/22 22:43:26 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>

t_object *check_position(t_ray *ray)
{
	t_vector	map_dim;
	t_vector	check_pos;
	
	map_dim.x = (int) map()->vector.w / GRID_SIZE;
	map_dim.y = (int) map()->vector.h / GRID_SIZE;
	check_pos.x = (int)(ray->cross.x / GRID_SIZE);
	check_pos.y = (int)(ray->cross.y / GRID_SIZE);
	if (check_pos.x >= 0 && check_pos.x < map_dim.x
		&& check_pos.y >= 0 && check_pos.y < map_dim.y
		&& map()->maps[(int) check_pos.y][(int) check_pos.x] != '0'
		)
			return (colison().rectangula_ob(scene()->player, (int)ray->cross.x , (int)ray->cross.y));
	else
		{
			ray->cross.x += ray->offset.x;
			ray->cross.y += ray->offset.y;
		}
	return NULL;
}

void 	update_rays(int max_loop, t_ray	*ray_ver, t_ray *ray_hor)
{
	int			loop;
	t_object	*obj;

	loop = -1;

	while (++loop < max_loop)
	{
		ray_ver->ob = check_position(ray_ver);
		ray_hor->ob= check_position(ray_hor);	
		if (ray_hor->ob && ray_ver->ob)
			break;
	}
}

t_ray	init_ray_hor(t_vector p, double angle)
{
	t_ray	ray;

	ray.vertical = 0;
	ray.collision = 0;
	ray.distance = 1e30;
	ray.ob = NULL;
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
	ray.ob = NULL;
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
	ray_hor = init_ray_hor(p, p.angle + rel_angle);
	update_rays(20, &ray_ver, &ray_hor);
	ray_ver.distance = get_vectors_distance(ray_ver.cross,
			p, p.angle + rel_angle);
	ray_hor.distance = get_vectors_distance(p, ray_hor.cross,
			p.angle + rel_angle);
	if (ray_ver.distance < ray_hor.distance)
		return (ray_ver);
	return (ray_hor);}