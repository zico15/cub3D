/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:03:46 by nprimo            #+#    #+#             */
/*   Updated: 2022/10/11 16:45:36 by nprimo           ###   ########.fr       */
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

typedef struct s_pos
{
	int x;
	int y;
}	t_pos;

typedef struct s_ray2
{
	t_v			camera;
	t_v			dir;
	t_v			side_dist;
	t_v			delta_dist;
	t_pos		step;
	t_pos		map_cell;
	int			hit;
	t_object	*obj;
	int			side;
} t_ray2;

static t_ray2	init_ray(t_player p, int x)
{
	t_ray2	ray;

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

static t_ray2	update_ray(t_ray2 ray)
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
		if (map()->maps[ray.map_cell.y][ray.map_cell.x] != '0')
			ray.hit = 1;
		// if ((map()->maps_ob[ray.map_cell.y][ray.map_cell.x])->type ==)

	}
	return (ray);
}

static void		draw_line(t_ray2 ray, int x)
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

void 			render_view2(t_player p) // receive player
{
	t_ray2		ray;
	double		perp_distance;
	int x;

	/* coming in with the player input */
	// position of the player
	// p.pos.x = p.vector.x / GRID_SIZE;
	// p.pos.y = p.vector.y / GRID_SIZE;
	// direction of the player - need to substitute the player angle
	// p.dir.x = -1;
	// p.dir.y = 0;
	// // view plane - need to be stored in the player as well
	// p.plane.x = 0;
	// p.plane.y = 0.66; // value with 66 FOV
	x = -1;
	while (++x < W_WIDTH)
	{
		ray = init_ray(p, x);
		ray = update_ray(ray);
		draw_line(ray, x);
	}
}
