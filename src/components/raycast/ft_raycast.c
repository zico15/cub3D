/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:57:49 by ezequeil          #+#    #+#             */
/*   Updated: 2022/09/21 19:21:14 by nprimo           ###   ########.fr       */
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

t_ray		get_ray_return(t_vector p, double rel_angle);	

// int checkboard[] = {
// 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
// 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
// 0,0,0,0,0,1,1,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
// 0,0,1,1,1,1,1,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
// 0,0,1,1,1,1,1,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
// 0,0,0,0,0,1,1,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
// 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
// 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,

// 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0,
// 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0,
// 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0,
// 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0,
// 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0,
// 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0,
// 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0,
// 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0,

// 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
// 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
// 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
// 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
// 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
// 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
// 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
// 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,

// 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0,
// 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0,
// 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0,
// 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0,
// 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0,
// 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0,
// 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0,
// 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0,
// };

t_texture	init_t(t_ray ray, t_vector column)
{
	t_texture	t;

	t.pos.x = (int) ray.cross.x % 32;
	if (ft_sin(ray.angle) < 0)
		t.pos.x = (int)(31.0 - t.pos.x);
	if (ray.vertical)
	{
		t.pos.x = (int) ray.cross.y % 32;
		if (ft_cos(ray.angle) < 0)
			t.pos.x = (int)(31.0 - t.pos.x);
	}
	t.y_offest = 0;
	t.y_step = 32.0 / (double) column.h;
	if (column.h >= W_HEIGHT)
	{
		t.y_offest = (column.h - W_HEIGHT) / 2.0;
		column.h = W_HEIGHT;
	}
	t.pos.y = t.y_offest * t.y_step;
	return (t);
}

void	print_column(t_ray ray, t_vector column)
{
	int				color;
	double			y;
	t_texture		t;
	static t_sprite	*sprite;

	if (ray.ob == NULL)
		return;
	if (!sprite)
		sprite = engine()->load_sprite("imgs/wall.xpm");
		// sprite = map()->map_ob->
	t = init_t(ray, column);
	if (column.h >= W_HEIGHT)
		column.h = W_HEIGHT;
	column.y = W_HEIGHT / 2 - column.h / 2;
	y = -1;
	while (++y < column.h)
	{
		color = __get_color(sprite->img, (int) t.pos.x, (int) t.pos.y);
		if (ray.vertical)
			color = color | 0x00555555; // shading ?
		(canva())->rectangle(vector(column.x, column.y + y, column.w, 1),
				color);
		t.pos.y += t.y_step;
	}
}

void	render_ray(t_ray ray, int pos, double rel_angle)
{
	double		dist_perp;
	t_vector	column;
	static int	colors[] = {GREEN, D_GREEN, RED, D_RED};

	dist_perp = ray.distance * ft_cos(rel_angle);
	column.h = (W_HEIGHT * 20 / dist_perp);
	column.w = W_WIDTH / N_RAYS;
	column.x = pos * column.w;
	print_column(ray, column);
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

void	render_view(t_player *p)
{
	double		rel_angle;
	t_ray		ray;
	int			color;
	int			i;

	rel_angle = VIEW_ANGLE / 2;
	i = -1;
	while (++i <= N_RAYS)
	{
		color = GREEN;
		ray = get_ray_return(p->vector, rel_angle);
		ray.direction = get_ray_direction(ray, p->vector.angle + rel_angle);
		render_ray(ray, i, rel_angle);
		rel_angle -= (double) VIEW_ANGLE / N_RAYS;
	}
}
