/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:03:46 by nprimo            #+#    #+#             */
/*   Updated: 2022/10/25 20:25:12 by edos-san         ###   ########.fr       */
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
		(canva())->pixel(x, t.draw_start.y + y, color);
		t.pos.y += t.y_step;
	}
}

void	draw_texture(t_ray *ray, int x, t_sprite *sprite)
{
	t_texture	t;

	t.line_h = (int)(win()->h / ray->perp_distance);
	t.pos.x = (int)(ray->cross * sprite->v.w);
	if ((ray->side == 0 && ray->dir.x > 0)
		|| (ray->side == 1 && ray->dir.y < 0))
		t.pos.x = sprite->v.w - 1 - t.pos.x;
	t.y_offset = 0;
	t.y_step = sprite->v.h / (double) t.line_h;
	if (t.line_h >= win()->h)
	{
		t.y_offset = (int)(t.line_h - win()->h) / 2.0;
		t.line_h = win()->h;
	}
	t.draw_start.y = win()->h / 2 - t.line_h / 2;
	t.pos.y = t.y_offset * t.y_step;
	draw_texture_loop(sprite, t, x);
}

double	get_ray_cross(t_ray ray)
{
	t_player	*p;
	double		cross;

	p = scene()->player;
	cross = p->vector.y + ray.perp_distance * ray.dir.y;
	if (ray.side == 1)
		cross = p->vector.x + ray.perp_distance * ray.dir.x;
	cross -= floor(cross);
	return (cross);
}

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
