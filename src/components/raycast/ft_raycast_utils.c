/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:39:41 by nprimo            #+#    #+#             */
/*   Updated: 2022/10/07 18:42:09 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>

void	render_ray(t_ray *ray);

static void check_position(t_ray *ray, t_vector p)
{
	int 		x;
	int			y;
	t_object	*ob;
	
	x = (int)(ray->cross.x / GRID_SIZE);
	y = (int)(ray->cross.y / GRID_SIZE);
	ob = NULL;
	if (x >= 0 && x < map()->size_width  \
	&& y >= 0 && y < map()->size_height && \
	map()->maps_ob[y][x])	 
		ob = map()->maps_ob[y][x];
	if (ob)
	{
		ray->distance = get_vectors_distance(ray->cross,
		p, p.angle + ray->rel_angle);
	}
	else
	{
		ray->cross.x += ray->offset.x;
		ray->cross.y += ray->offset.y;
	}
	ray->ob = ob;
}


static int	render_object(t_ray *ray_ver, t_ray *ray_hor)
{
	static t_ray		*ray;

	if (ray_ver->distance < ray_hor->distance)
			ray = ray_ver;
		else
			ray = ray_hor;
	if (ray->ob)
		render_ray(ray);
	return (ray_hor->ob && ray_ver->ob);
}

void 	update_rays(int max_loop, t_ray	*ray_ver, t_ray *ray_hor, t_vector p)
{
	int				loop;
	int				i;

	loop = -1;
	while (++loop < max_loop)
	{
		if (!ray_ver->ob)
			check_position(ray_ver, p);
		if (!ray_hor->ob)
			check_position(ray_hor, p);
		if (ray_hor->ob || ray_ver->ob)		
			if (render_object(ray_ver, ray_hor))
				break;
	}
}

void	get_ray_direction(t_ray *ray, double angle)
{
	if (ft_cos(angle) >= 0 && ray->vertical == 1)
		ray->direction = W;
	if (ft_cos(angle) <= 0 && ray->vertical == 1)
		ray->direction = E;
	if (ft_sin(angle) >= 0 && ray->vertical == 0)
		ray->direction = S;
	if (ft_sin(angle) <= 0 && ray->vertical == 0)
		ray->direction = N;
}

void	init_ray_hor(t_vector p, double angle)
{

	ray_hor()->vertical = 0;
	ray_hor()->collision = 0;
	ray_hor()->distance = 1e30;
	ray_hor()->ob = NULL;
	ray_hor()->angle = angle;
	get_ray_direction(ray_hor(), angle);
	if (ft_sin(angle) > 0)
	{
		ray_hor()->cross.y = ((int) p.y / GRID_SIZE) * GRID_SIZE - 0.0001;
		ray_hor()->offset.y = -GRID_SIZE;
	}
	else if (ft_sin(angle) < 0)
	{
		ray_hor()->cross.y = ((int) p.y / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
		ray_hor()->offset.y = GRID_SIZE;
	}
	if (angle == 180 || angle == 0 || angle == 360)
	{
		ray_hor()->collision = 1;
		ray_hor()->cross.y = INT_MIN;
	}
	ray_hor()->cross.x = (p.y - ray_hor()->cross.y) / ft_tan(angle) + p.x;
	ray_hor()->offset.x = -ray_hor()->offset.y / ft_tan(angle);
}

void	init_ray_ver(t_vector p, double angle)
{
	
	ray_ver()->vertical = 1;
	ray_ver()->collision = 0;
	ray_ver()->distance = 1e30;
	ray_ver()->ob = NULL;
	ray_ver()->angle = angle;
	get_ray_direction(ray_ver(), angle);
	if (ft_cos(angle) < 0)
	{
		ray_ver()->cross.x = ((int) p.x / GRID_SIZE) * GRID_SIZE - 0.0001;
		ray_ver()->offset.x = -GRID_SIZE;
	}
	else if (ft_cos(angle) > 0)
	{
		ray_ver()->cross.x = ((int) p.x / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
		ray_ver()->offset.x = GRID_SIZE;
	}
	if (angle == 90 || angle == 270)
	{
		ray_ver()->collision = 1;
		ray_ver()->cross.x = INT_MIN;
	}
	ray_ver()->cross.y = (p.x - ray_ver()->cross.x) * ft_tan(angle) + p.y;
	ray_ver()->offset.y = -ray_ver()->offset.x * ft_tan(angle);
}

void	get_ray_return(t_vector p, double rel_angle, int pos)
{
	int		max_loop;


	init_ray_ver(p, p.angle + rel_angle);
	init_ray_hor(p, p.angle + rel_angle);
	ray_ver()->pos = pos;
	ray_ver()->rel_angle = rel_angle;
	ray_hor()->pos = pos;
	ray_hor()->rel_angle = rel_angle;
	update_rays(50, ray_ver(), ray_hor(), p);
}