/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:39:41 by nprimo            #+#    #+#             */
/*   Updated: 2022/10/05 18:32:39 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>

void	render_ray(t_ray *ray);

static t_ray *check_position(t_ray *ray, t_vector p)
{
	int 		x;
	int			y;
	t_object	*ob;
	
	x = (int)(ray->cross.x / GRID_SIZE);
	y = (int)(ray->cross.y / GRID_SIZE);
	ob = NULL;
	if (x >= 0 && x < map()->size_width  \
	&& y >= 0 && y < map()->size_height && map()->maps[y][x] != '0')
		ob = colison().pixel((t_object *) scene()->player, (int)ray->cross.x , (int)ray->cross.y);
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
	return (ray);
}


static int	render_object(t_ray *ray_ver, t_ray *ray_hor)
{
	t_ray		*ray;

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
			ray_ver = check_position(ray_ver, p);
		if (!ray_hor->ob)
			ray_hor = check_position(ray_hor, p);
		if (ray_hor->ob || ray_ver->ob)		
			if (render_object(ray_ver, ray_hor))
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