/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:03:46 by nprimo            #+#    #+#             */
/*   Updated: 2022/10/14 19:35:36 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

static void	draw_texture_loop(t_sprite *sprite, t_texture t, int x)
{
	int	color;
	int	y;

	y = -1;
	while (++y < t.line_h)
	{
		color = __get_color_sprite(sprite, (int) t.pos.x, (int) t.pos.y);
		(canva())->pixel(x, t.draw_start_y + y, color);
		t.pos.y += t.y_step;
	}
}

void	draw_texture(t_ray *ray, int x, t_sprite *sprite)
{
	t_texture	t;
	int			y;
	int			color;

	t.line_h = (int)(W_HEIGHT / ray->perp_distance);
	t.pos.x = (int)(ray->cross * sprite->v.w);
	if ((ray->side == 0 && ray->dir.x > 0)
		|| (ray->side == 1 && ray->dir.y < 0))
		t.pos.x = sprite->v.w - 1 - t.pos.x;
	t.y_offset = 0;
	t.y_step = sprite->v.h / (double) t.line_h;
	if (t.line_h >= W_HEIGHT)
	{
		t.y_offset = (int)(t.line_h - W_HEIGHT) / 2.0;
		t.line_h = W_HEIGHT;
	}
	t.draw_start_y = W_HEIGHT / 2 - t.line_h / 2;
	t.pos.y = t.y_offset * t.y_step;
	y = -1;
	draw_texture_loop(sprite, t, x);
}

double	get_ray_cross(t_ray ray)
{
	t_player	*p;
	double		cross;

	p = scene()->player;
	cross = p->pos.y + ray.perp_distance * ray.dir.y;
	if (ray.side == 1)
		cross = p->pos.x + ray.perp_distance * ray.dir.x;
	cross -= floor(cross);
	return (cross);
}

/* to check if it return the right face */
t_face	get_face_dir(t_ray ray)
{
	t_face	face_dir;

	if (ray.dir.y > 0 && ray.side == 1)
		face_dir = N;
	if (ray.dir.x > 0 && ray.side == 0)
		face_dir = E;
	if (ray.dir.x < 0 && ray.side == 0)
		face_dir = W;
	if (ray.dir.y < 0 && ray.side == 1)
		face_dir = S;
	return (face_dir);
}
