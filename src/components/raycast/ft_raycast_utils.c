/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:39:41 by nprimo            #+#    #+#             */
/*   Updated: 2022/10/09 14:36:16 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>

// void	render_ray(t_ray *ray);

static t_ray check_position(t_ray ray, t_vector p)
{
	int 		x;
	int			y;
	t_object	*ob;
	
	x = (int)(ray.cross.x / GRID_SIZE);
	y = (int)(ray.cross.y / GRID_SIZE);
	ob = NULL;
	if (x >= 0 && x < map()->size_width
			&& y >= 0 && y < map()->size_height
			// && map()->maps_ob[y][x]
			&& map()->maps[y][x] != '0'
	)
	{
		// ray.ob = map()->maps_ob[y][x];
		ray.distance = get_vectors_distance(ray.cross,
			p, ray.rel_angle);
		/* collision might be useless if using obj
		// obj == NULL no collision // obj.type == 'something' collision happened
		*/
		ray.collision = 1; 
		ray.loop = 0;
	}
	else
	{
		ray.cross.x += ray.offset.x;
		ray.cross.y += ray.offset.y;
		ray.loop--;
	}
	return (ray);
}

/*
	not used now - to refactor 
*/
static int	render_object(t_ray *ray_ver, t_ray *ray_hor)
{
	static t_ray		*ray;

	if (ray_ver->distance < ray_hor->distance)
			ray = ray_ver;
		else
			ray = ray_hor;
	// if (ray->ob)
		// render_ray(ray);
	if (ray->collision)
		print_ray_2d(ray);
	return (ray_hor->ob || ray_ver->ob);
}

t_ray 	update_rays(t_ray ray_ver, t_ray ray_hor, t_vector p)
{
	int				i;

	while (ray_ver.loop || ray_hor.loop)
	{
		if (ray_ver.loop && !ray_ver.collision)
			ray_ver = check_position(ray_ver, p);
		if (ray_hor.loop && !ray_hor.collision)
			ray_hor = check_position(ray_hor, p);
		// if (ray_hor.ob || ray_ver.ob)	
	// 		if (render_object(ray_ver, ray_hor))
	// 			break;
		if (ray_hor.collision || ray_ver.collision)
		{
			if (ray_hor.distance < ray_ver.distance)
				return (ray_hor);
			else
				return (ray_ver);
			break;
		}
	}
	// this might cause error
	return (ray_hor);
}

t_face	get_ray_direction(t_ray *ray, double angle)
{
	t_face	direction;
 
	if (ft_cos(angle) >= 0 && ray->vertical == 1)
		direction = W;
	if (ft_cos(angle) <= 0 && ray->vertical == 1)
		direction = E;
	if (ft_sin(angle) >= 0 && ray->vertical == 0)
		direction = S;
	if (ft_sin(angle) <= 0 && ray->vertical == 0)
		direction = N;
	return (direction);
}

t_ray	init_ray_hor(t_vector p, double angle)
{
	t_ray	ray_hor;

	ray_hor.vertical = 0;
	ray_hor.collision = 0;
	ray_hor.loop = map()->size_height;
	ray_hor.distance = 1e30;
	ray_hor.ob = NULL;
	ray_hor.angle = angle;
	ray_hor.direction = get_ray_direction(&ray_hor, angle);
	if (ft_sin(angle) > 0)
	{
		ray_hor.cross.y = ((int)((int) p.y>>5)<<5) - 0.001;
		ray_hor.offset.y = -GRID_SIZE;
	}
	else if (ft_sin(angle) < 0)
	{
		ray_hor.cross.y = ((int) p.y>>5) * GRID_SIZE + GRID_SIZE;
		ray_hor.offset.y = GRID_SIZE;
	}
	if (angle == 180 || angle == 0 || angle == 360)
		ray_hor.loop = 0;
	ray_hor.cross.x = (p.y - ray_hor.cross.y) / ft_tan(angle) + p.x;
	ray_hor.offset.x = -ray_hor.offset.y / ft_tan(angle);
	return (ray_hor);
}

t_ray	init_ray_ver(t_vector p, double angle)
{
	t_ray	ray_ver;

	ray_ver.vertical = 1;
	ray_ver.collision = 0;
	ray_ver.loop = map()->size_width;
	ray_ver.distance = 1e30;
	ray_ver.ob = NULL;
	ray_ver.angle = angle;
	ray_ver.direction = get_ray_direction(&ray_ver, angle);
	if (ft_cos(angle) < 0)
	{
		ray_ver.cross.x = ((int) p.x / GRID_SIZE) * GRID_SIZE - 0.0001;
		ray_ver.offset.x = -GRID_SIZE;
	}
	else if (ft_cos(angle) > 0)
	{
		ray_ver.cross.x = ((int) p.x / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
		ray_ver.offset.x = GRID_SIZE;
	}
	if (angle == 90 || angle == 270)
		ray_ver.loop = 0;
	ray_ver.cross.y = (p.x - ray_ver.cross.x) * ft_tan(angle) + p.y;
	ray_ver.offset.y = -ray_ver.offset.x * ft_tan(angle);
	return (ray_ver);
}

t_ray	get_ray_return(t_vector p, double rel_angle, int pos)
{
	t_ray	ray_ver;
	t_ray	ray_hor;

	ray_ver = init_ray_ver(p, p.angle + rel_angle);
	ray_hor = init_ray_hor(p, p.angle + rel_angle);
	ray_ver.pos = pos;
	ray_ver.rel_angle = rel_angle;
	ray_hor.pos = pos;
	ray_hor.rel_angle = rel_angle;
	return (update_rays(ray_ver, ray_hor, p));
}