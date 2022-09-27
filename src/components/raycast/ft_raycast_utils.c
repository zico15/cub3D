/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:39:41 by nprimo            #+#    #+#             */
/*   Updated: 2022/09/23 00:09:59 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>

void	render_ray(t_ray *ray);

static t_ray *check_position(t_ray *ray, t_vector p)
{
	t_vector	check_pos;
	t_object	*ob;
	
	check_pos.x = (int)(ray->cross.x / GRID_SIZE);
	check_pos.y = (int)(ray->cross.y / GRID_SIZE);
	ob = colison().pixel((t_object *) scene()->player, (int)ray->cross.x , (int)ray->cross.y);
	if (check_pos.x >= 0 && check_pos.x < map()->size_width
		&& check_pos.y >= 0 && check_pos.y < map()->size_height
		&& ob
		)
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
	return (ray);
}


static int	render_object(t_ray *ray_ver, t_ray *ray_hor, t_ray	*rays)
{
	t_ray		*ray;
	int			i;

	i = 0;
	if (ray_ver->distance < ray_hor->distance)
			ray = ray_ver;
		else
			ray = ray_hor;
	if (ray->ob && ray->ob->type == WALL)
		render_ray(ray);
	else
	{	
		rays[i] = *ray;
		ray->ob = NULL;
	}
	return (ray_hor->ob && ray_ver->ob);
}

void 	update_rays(int max_loop, t_ray	*ray_ver, t_ray *ray_hor, t_vector p)
{
	int			loop;
	t_ray		rays[9999];
	int			i;

	loop = -1;
	i = 0;
	while (++loop < max_loop)
	{
		if (!ray_ver->ob || ray_ver->ob->type != WALL)
			ray_ver = check_position(ray_ver, p);
		if (!ray_hor->ob || ray_hor->ob->type != WALL)
			ray_hor = check_position(ray_hor, p);	
		if (ray_hor->ob || ray_ver->ob)
			if (render_object(ray_ver, ray_hor, &rays))
				break;
	}
}

char	get_ray_direction(t_ray ray, double angle)
{
	t_face	dir;

	if (ft_cos(angle) >= 0 && ray.vertical == 1)
		dir = W;
	if (ft_cos(angle) <= 0 && ray.vertical == 1)
		dir = E;
	if (ft_sin(angle) >= 0 && ray.vertical == 0)
		dir = S;
	if (ft_sin(angle) <= 0 && ray.vertical == 0)
		dir = N;
	return (dir);
}

t_ray	init_ray_hor(t_vector p, double angle)
{
	static t_ray	ray;

	ray.vertical = 0;
	ray.collision = 0;
	ray.distance = 1e30;
	ray.ob = NULL;
	ray.angle = angle;
	ray.direction = get_ray_direction(ray, angle);
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
	static t_ray	ray;

	ray.vertical = 1;
	ray.collision = 0;
	ray.distance = 1e30;
	ray.ob = NULL;
	ray.angle = angle;
	ray.direction = get_ray_direction(ray, angle);
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

t_ray	get_ray_return(t_vector p, double rel_angle, int pos)
{
	t_ray	ray_ver;
	t_ray	ray_hor;
	int		max_loop;


	ray_ver = init_ray_ver(p, p.angle + rel_angle);
	ray_hor = init_ray_hor(p, p.angle + rel_angle);
	ray_ver.pos = pos;
	ray_ver.rel_angle = rel_angle;
	ray_hor.pos = pos;
	ray_hor.rel_angle = rel_angle;
	update_rays(50, &ray_ver, &ray_hor, p);
	return (ray_hor);
}