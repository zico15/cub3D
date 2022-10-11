/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:03:46 by nprimo            #+#    #+#             */
/*   Updated: 2022/10/11 20:02:12 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

#define mapWidth 24
#define mapHeight 24

#define YELLOW 0x00FFFF00
#define GREEN 0x000000ff
#define RED 0x00ff0000
#define BLUE 0x0000ff00
#define WHITE 0xffffffff

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

static double	get_ray_cross(t_ray ray)
{
	t_player	*p;
	double	cross;

	p = scene()->player;
	cross = p->pos.y + ray.perp_distance * ray.dir.x;
	if (ray.side == 1)
		cross = p->pos.x + ray.perp_distance * ray.dir.y;
	cross -= floor(cross);
	return (cross);
}

static t_ray	update_ray(t_ray ray)
{
	while (ray.hit == 0)
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
		if (map()->maps_ob[ray.map_cell.y][ray.map_cell.x])
		{
			ray.hit = 1;
			ray.cross = get_ray_cross(ray);
			ray.obj = map()->maps_ob[ray.map_cell.y][ray.map_cell.x];
			if (ray.side == 0)
				ray.perp_distance = ray.side_dist.x - ray.delta_dist.x;
			else
				ray.perp_distance = ray.side_dist.y - ray.delta_dist.y;
		}
	}
	return (ray);
}

static void	draw_line(t_ray ray, int x)
{
	int 	color;
	int 	line_h;
	t_pos	draw_h;

	line_h = (int) (W_HEIGHT / ray.perp_distance);
	draw_h.x = - line_h / 2 + W_HEIGHT / 2;
	if (draw_h.x < 0)
		draw_h.x = 0;
	draw_h.y = line_h / 2 + W_HEIGHT / 2;
	if (draw_h.y >+ W_HEIGHT)
		draw_h.y = W_HEIGHT - 1;
	color = YELLOW;
	if (ray.side == 1)
		color = color / 2;
	(canva())->line(vector(x, draw_h.x, 0, 0), vector(x, draw_h.y, 0, 0), color);
}

static void	draw_texture(t_ray *ray, int x)
{
	t_texture	t;
	t_vector	column;
	t_player	*p;
	t_sprite	*sprite;
	int			y;
	int			color;

	column.h = (int) (W_HEIGHT / ray->perp_distance);
	column.x = x;
	p = scene()->player;
	t.pos.x = (int)(ray->cross * 32.0);
	if ((ray->side == 0 && ray->dir.x > 0)
		|| (ray->side == 1 && ray->dir.y < 0))
		t.pos.x = 32.0 - 1 - t.pos.x;
	t.y_offset = 0;
	t.y_step = 32.0 / (double) column.h;
	if (column.h >= W_HEIGHT)
	{
		t.y_offset = (int) (column.h - W_HEIGHT) / 2.0;
		column.h = W_HEIGHT;
	}
	column.y = W_HEIGHT / 2 - column.h / 2;
	t.pos.y = t.y_offset * t.y_step;
	sprite = ray->obj->get_sprite(*ray);
	y = -1;
	while (++y < column.h)
	{
		color = __get_color_sprite(sprite, (int) t.pos.x, (int) t.pos.y);
		(canva())->pixel(x, column.y + y, color);
		t.pos.y += t.y_step;
	}
}

void	render_view2(t_player p) // receive player
{
	t_ray		ray;
	int			x;
	t_texture	t;

	x = -1;
	while (++x < W_WIDTH)
	{
		ray = init_ray(p, x);
		ray = update_ray(ray);
		draw_texture(&ray, x);
		// draw_line(ray, x);
	}
}
