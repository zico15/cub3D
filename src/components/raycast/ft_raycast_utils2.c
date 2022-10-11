/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:03:46 by nprimo            #+#    #+#             */
/*   Updated: 2022/10/11 18:41:05 by nprimo           ###   ########.fr       */
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

// typedef struct s_ray2
// {
// 	t_vector	camera;
// 	t_vector	dir;
// 	t_vector	side_dist;
// 	t_vector	delta_dist;
// 	t_vector	cross;
// 	t_pos		step;
// 	t_pos		map_cell;
// 	int			hit;
// 	t_object	*obj;
// 	int			side;
// } t_ray2;

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

static t_vector	get_ray_cross(t_ray ray)
{
	t_player	*p;
	t_vector	cross;
	double		vect_len;
	double		cross_len;

	p = scene()->player;
	vect_len = p->dir.x * p->dir.x + p->dir.y * p->dir.y;
	cross_len = ray.side_dist.x * ray.side_dist.x;
	if (ray.side_dist.y < ray.side_dist.x)
		cross_len = ray.side_dist.y * ray.side_dist.y;
	cross.x = cross_len * ray.dir.x / vect_len;
	cross.y = cross_len * ray.dir.y / vect_len;
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
		}
	}
	return (ray);
}

static void	draw_line(t_ray ray, int x)
{
	double	perp_distance;
	int 	color;
	int 	line_h;
	t_pos	draw_h;

	if (ray.side == 0)
		perp_distance = ray.side_dist.x - ray.delta_dist.x;
	else
		perp_distance = ray.side_dist.y - ray.delta_dist.y;
	line_h = (int) (W_HEIGHT / perp_distance);
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

// static t_texture	init_t(t_ray *ray, t_vector column)
// {
// 	t_texture	t;
	
// 	t.pos.x = (int) ray->cross.x % 32;
// 	if (ft_sin(ray->angle) < 0)
// 		t.pos.x = (int)(31.0 - t.pos.x);
// 	if (ray->vertical)
// 	{
// 		t.pos.x = (int) ray->cross.y % 32;
// 		if (ft_cos(ray->angle) < 0)
// 			t.pos.x = (int)(31.0 - t.pos.x);
// 	}
// 	t.y_offset = 0;
// 	t.y_step = 32.0 / (double) column.h;
// 	if (column.h >= W_HEIGHT)
// 	{
// 		t.y_offset = (column.h - W_HEIGHT) / 2.0;
// 		column.h = W_HEIGHT;
// 	}
// 	t.pos.y = t.y_offset * t.y_step;
// 	return (t);
// }

// static void	print_column(t_ray *ray, t_vector column, int x)
// {
// 	int				color;
// 	double			y;
// 	t_texture		t;
// 	t_sprite		*sprite;
// 	t_vector		column;

// 	if (!ray->obj)
// 		return ;
// 	column.w = 1;
// 	column.x = x;
// 	if (ray->obj == NULL)
// 		return;
// 	sprite = ray->obj->get_sprite(*ray);
// 	t = init_t(ray, column);
// 	if (column.h >= W_HEIGHT)
// 		column.h = W_HEIGHT;
// 	column.y = W_HEIGHT / 2 - column.h / 2;
// 	y = -1;
// 	while (++y < column.h)
// 	{
// 		color = __get_color_sprite(sprite, (int) t.pos.x, (int) t.pos.y);
// 		(canva())->rectangle(vector(column.x, column.y + y, column.w, 1),
// 				color);
// 		t.pos.y += t.y_step;
// 	}
// }

void	render_view2(t_player p) // receive player
{
	t_ray	ray;
	int		x;

	x = -1;
	while (++x < W_WIDTH)
	{
		ray = init_ray(p, x);
		ray = update_ray(ray);
		draw_line(ray, x);
	}
}
