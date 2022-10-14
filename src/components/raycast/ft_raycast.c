/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:57:49 by ezequeil          #+#    #+#             */
/*   Updated: 2022/10/14 18:09:42 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_object.h>

#define GREEN 0x0000FF00
#define D_GREEN 0x00cc00
#define RED 0x00ff0000
#define D_RED 0x00cc0000
#define WHITE 0x00000000
#define BLACK 0xffffffff

double			get_ray_cross(t_ray ray);
void			draw_texture(t_ray *ray, int x, t_sprite *sprite);

static void		render_ray(t_ray ray, int x);
static t_ray	init_ray(t_player p, int x);

void	render_view(t_player *p)
{
	int			x;
	t_texture	t;

	x = -1;
	while (++x < W_WIDTH)
		render_ray(init_ray(*p, x), x);
}

static t_ray	update_ray(t_ray ray)
{
	if (ray.side_dist.x < ray.side_dist.y)
	{
		ray.side_dist.x += ray.delta_dist.x;
		ray.map_cell.x += ray.step.x;
		ray.side = 0;
	}
	else
	{
		ray.side_dist.y += ray.delta_dist.y;
		ray.map_cell.y += ray.step.y;
		ray.side = 1;
	}
	return (ray);
}

static void	render_ray(t_ray ray, int x)
{
	ray.obj = NULL;
	while (ray.obj == NULL)
	{
		ray = update_ray(ray);
		if (map()->maps_ob[ray.map_cell.y][ray.map_cell.x])
		{
			ray.obj = map()->maps_ob[ray.map_cell.y][ray.map_cell.x];
			if (ray.side == 0)
				ray.perp_distance = ray.side_dist.x - ray.delta_dist.x;
			else
				ray.perp_distance = ray.side_dist.y - ray.delta_dist.y;
			ray.cross = get_ray_cross(ray);
			if (ray.obj->type != WALL)
				render_ray(ray, x);
			draw_texture(&ray, x, ray.obj->get_sprite(ray));
		}
	}
}

static t_ray	init_ray2(t_ray ray, t_player p)
{
	if (ray.dir.x < 0)
	{
		ray.step.x = -1;
		ray.side_dist.x = (p.pos.x - ray.map_cell.x) * ray.delta_dist.x;
	}
	else
	{
		ray.step.x = 1;
		ray.side_dist.x = (ray.map_cell.x + 1 - p.pos.x) * ray.delta_dist.x;
	}
	if (ray.dir.y < 0)
	{
		ray.step.y = -1;
		ray.side_dist.y = (p.pos.y - ray.map_cell.y) * ray.delta_dist.y;
	}
	else
	{
		ray.step.y = 1;
		ray.side_dist.y = (ray.map_cell.y + 1 - p.pos.y) * ray.delta_dist.y;
	}
	return (ray);
}

static t_ray	init_ray(t_player p, int x)
{
	t_ray	ray;

	ray.hit = 0;
	ray.camera.x = 2 * x / (double) W_WIDTH - 1;
	ray.dir.x = p.dir.x + p.plane.x * ray.camera.x;
	ray.dir.y = p.dir.y + p.plane.y * ray.camera.x;
	ray.map_cell.x = (int) p.pos.x;
	ray.map_cell.y = (int) p.pos.y;
	if (ray.dir.x == 0)
		ray.delta_dist.x = 1e30;
	else
		ray.delta_dist.x = fabs(1 / ray.dir.x);
	if (ray.dir.y == 0)
		ray.delta_dist.y = 1e30;
	else
		ray.delta_dist.y = fabs(1 / ray.dir.y);
	return (init_ray2(ray, p));
}
