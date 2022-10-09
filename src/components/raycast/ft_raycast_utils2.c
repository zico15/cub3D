/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:03:46 by nprimo            #+#    #+#             */
/*   Updated: 2022/10/09 19:13:39 by nprimo           ###   ########.fr       */
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

typedef struct	s_v
{
	double x;
	double y;
}	t_v;

typedef struct s_pos
{
	int x;
	int y;
}	t_pos;

int worldMap[mapWidth][mapHeight] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	print_map()
{
	int x;
	int y;

	y = 0;
	while(y < mapHeight)
	{
		x = 0;
		while (x < mapWidth)
		{
			printf("%d ", worldMap[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("=========================\n\n");
}

static void	render_ray2(t_v pos, t_v dir, t_v plane, int x)
{
	t_v	camera;
	t_v ray_dir;
	t_v	side_dist;
	t_v	delta_dist;
	t_pos	map_cell;
	t_pos step;
	int	side = 0;

	// print_map();

	camera.x = 2 * x / (double) W_WIDTH - 1; 
	ray_dir.x = dir.x + plane.x * camera.x;
	ray_dir.y = dir.y + plane.y * camera.x;
	map_cell.x = (int) pos.x;
	map_cell.y = (int) pos.y;
	if (ray_dir.x == 0)
		delta_dist.x = 1e30;
	else
		delta_dist.x = abs(1 / ray_dir.x);
	if (ray_dir.y == 0)
		delta_dist.y = 1e30;
	else
		delta_dist.y = abs(1 / ray_dir.y);
	if (ray_dir.x < 0)
	{
		step.x = -1;
		side_dist.x = (pos.x - map_cell.x) * delta_dist.x;
	}
	else
	{
		step.x = 1;
		side_dist.x = (map_cell.x + 1 - pos.x) * delta_dist.x;
	}
	if (ray_dir.y < 0)
	{
		step.y = -1;
		side_dist.y = (pos.y - map_cell.y) * delta_dist.y;
	}
	else
	{
		step.y = 1;
		side_dist.y = (map_cell.y + 1 - pos.y) * delta_dist.y;
	}

	int hit = 0;
	while (hit == 0)
	{
		if (side_dist.x < side_dist.y)
		{
			side_dist.x += delta_dist.x;
			map_cell.x += step.x;
			side = 0;
		}
		else
		{
			side_dist.y += delta_dist.y;
			map_cell.y += step.y;
			side = 1;
		}
		if (worldMap[map_cell.y][map_cell.x] > 0)
			hit = 1;
	}
	// =====================
	double perp_distance;
	if (side == 0)
		perp_distance = side_dist.x - delta_dist.x;
	else
		perp_distance = side_dist.y - delta_dist.y;
	// ====================
	int line_h;
	t_pos	draw_h;
	
	line_h = (int) (W_HEIGHT / perp_distance);
	draw_h.x = - line_h / 2 + W_HEIGHT / 2;
	if (draw_h.x < 0)
		draw_h.x = 0;
	draw_h.y = line_h / 2 + W_HEIGHT / 2;
	if (draw_h.y >+ W_HEIGHT)
		draw_h.y = W_HEIGHT - 1;

	// ==================
	int color;
	int	map_value;

	map_value = worldMap[map_cell.y][map_cell.x];
	color = YELLOW;
	if (map_value == 1)
		color = RED;
	if (map_value == 2)
		color = GREEN;
	if (map_value == 3)
		color = BLUE;
	if (map_value == 4)
		color = WHITE;
	canva()->line(vector(x, draw_h.x, 0, 0), vector(x, draw_h.y, 0, 0), color);
}

void main_render()
{
	t_v pos;
	t_v plane;
	t_v	dir;
	int x;

	pos.x = 22;
	pos.y = 12;
	dir.x = -1;
	dir.y = 0;
	plane.x = 0;
	plane.y = 0.66;
	x = -1;
	while (++x < W_WIDTH)
		render_ray2(pos, dir, plane, x);
}