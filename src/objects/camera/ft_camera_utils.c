/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:37:32 by nprimo            #+#    #+#             */
/*   Updated: 2023/03/08 15:01:16 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

static void	draw_object(double screen_x, t_vector transform, t_object *obj);
static void	draw_stripe(
				int stripe, t_texture t, t_object *obj, double screen_x);
static void	render_object(t_object *obj, t_player *player);
void		swap_list(t_element *e, t_object	**obs, int index);

void	render_object_list(void)
{
	t_element			*e;
	t_object			*obj;
	t_player			*player;
	static t_object		*objs[2090];
	int					i;

	player = scene()->player;
	e = array(scene()->free_objects)->begin;
	while (e)
	{
		obj = e->value;
		obj->vector.distance = ((player->vector.x - obj->vector.x) * \
		(player->vector.x - obj->vector.x) + (player->vector.y - \
		obj->vector.y) * (player->vector.y - obj->vector.y));
		e = e->next;
	}
	swap_list(array(scene()->free_objects)->begin, objs, 0);
	objs[array(scene()->free_objects)->size] = NULL;
	i = -1;
	while (objs[++i] != NULL)
	{
		render_object(objs[i], player);
		objs[i] = NULL;
	}
}

static void	render_object(t_object *obj, t_player *player)
{
	t_vector	rel_pos;
	t_vector	transform;
	double		screen_x;
	double		inv_det;

	rel_pos.x = obj->vector.x - player->vector.x + 0.5;
	rel_pos.y = obj->vector.y - player->vector.y + 0.5;
	inv_det = 1.0 / (player->plane.x * player->dir.y
			- player->dir.x * player->plane.y);
	transform.x = inv_det * (player->dir.y * rel_pos.x
			- player->dir.x * rel_pos.y);
	transform.y = inv_det * (-player->plane.y * rel_pos.x
			+ player->plane.x * rel_pos.y);
	screen_x = ((int)(win()->w / 2)) * (1 + transform.x / transform.y);
	draw_object(screen_x, transform, obj);
}

static t_texture	init_draw_start_end(
		t_object *obj, t_vector transform, double screen_x)
{
	t_texture	t;

	obj->vector.h = abs((int)(win()->h / transform.y));
	t.draw_start.y = -obj->vector.h / 2 + win()->h / 2;
	if (t.draw_start.y < 0)
		t.draw_start.y = 0;
	t.draw_end.y = obj->vector.h / 2 + win()->h / 2;
	if (t.draw_end.y > win()->h)
		t.draw_end.y = win()->h - 1;
	obj->vector.w = abs((int)(win()->h / transform.y));
	t.draw_start.x = -obj->vector.w + screen_x;
	if (t.draw_start.x < 0)
		t.draw_start.x = 0;
	t.draw_end.x = obj->vector.w / 2 + screen_x;
	if (t.draw_end.x > win()->w)
		t.draw_end.x = win()->w - 1;
	return (t);
}

static void	draw_object(double screen_x, t_vector transform, t_object *obj)
{
	int			stripe;
	t_texture	t;
	t_camera	*camera;

	t = init_draw_start_end(obj, transform, screen_x);
	camera = fthis()->camera;
	stripe = t.draw_start.x - 1;
	while (++stripe < t.draw_end.x)
	{
		if (transform.y > 0 && stripe > 0 && stripe < win()->w
			&& transform.y < camera->perp_distance_wall[stripe])
			draw_stripe(stripe, t, obj, screen_x);
	}
}

static void	draw_stripe(
		int stripe, t_texture t, t_object *obj, double screen_x)
{
	int			color;
	int			y;

	y = t.draw_start.y - 1;
	if (obj && stripe == (win()->w / 2))
		scene()->player->mira = obj;
	while (++y < t.draw_end.y)
	{
		t.pos.x = (int)(256 * (stripe - (-obj->vector.w / 2 + screen_x))
				* obj->sprite->v.w / obj->vector.w) / 256;
		t.pos.y = (int)(((int)(y * 256 - win()->h * 128 + \
		(obj->vector.h) * 128) *obj->sprite->v.h) / obj->vector.h) / 256;
		color = __get_color_sprite(obj->sprite, t.pos.x, t.pos.y);
		((canva())->pixel(stripe, y, color));
	}
}
