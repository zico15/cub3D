/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:20:00 by nprimo            #+#    #+#             */
/*   Updated: 2022/10/18 16:38:34 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>

void	render_view(t_player *p);
void	render_objects(t_camera *camera);

static void	__render(t_buffer *b)
{
	render_view(scene()->player);
	render_objects(fthis()->camera);
}

t_object	*new_camera(void)
{
	t_camera	*camera;

	camera = new_object_instance(sizeof(t_camera));
	camera->render = __render;
	camera->vector = vector(0, 0, W_WIDTH, W_HEIGHT);
	fthis()->camera = camera;
	fthis()->scene->camera = camera;
	return ((t_object *) camera);
}

void	render_objects(t_camera *camera)
{
	t_element	*e;
	t_object	*obj;
	t_player	*player;

	player = scene()->player;
	e = array(scene()->enemies)->begin;
	while (e)
	{
		obj = e->value;
		
		t_vector	rel_pos;
		t_vector	transform;
		t_vector	screen;
		t_vector	obj_dim;
		double		inv_det;

		rel_pos.x = obj->vector.x - player->vector.x;
		rel_pos.y = obj->vector.y - player->vector.y;
		inv_det = 1.0 / (player->plane.x * player->dir.y - player->dir.x * player->plane.y);
		transform.x = inv_det * (player->dir.y * rel_pos.x - player->dir.x * rel_pos.y);
		transform.y = inv_det * (-player->plane.y * rel_pos.x + player->plane.x * rel_pos.y);
		screen.x = (int)(W_WIDTH / 2) * (1 + transform.x / transform.y);
		
		t_vector	draw_start;
		t_vector	draw_end;

		obj->vector.h = abs((int)(W_HEIGHT / transform.y));
		draw_start.y = -obj->vector.h / 2 + W_HEIGHT / 2;
		if (draw_start.y < 0)
			draw_start.y = 0;
		draw_end.y = obj->vector.h / 2 + W_HEIGHT / 2;
		if (draw_end.y > W_HEIGHT)
			draw_end.y = W_HEIGHT - 1;
		obj->vector.w = abs((int)(W_HEIGHT / transform.y));
		draw_start.x = -obj->vector.w + screen.x;
		if (draw_start.x < 0)
			draw_start.x = 0;
		draw_end.x = obj->vector.w / 2 + screen.x;
		if (draw_end.x > W_WIDTH)
			draw_end.x = W_WIDTH - 1;
		
		int stripe;

		stripe = draw_start.x - 1;
		while (++stripe < draw_end.x)
		{
			if (transform.y > 0 && stripe > 0 && stripe < W_WIDTH
					&& transform.y < camera->perp_distance_wall[stripe])
			{
				int	y;
				y = draw_start.y - 1; 
				while (++y < draw_end.y)
				{
					t_texture	t;
					int			color;

					t.pos.x = (int)(256 * (stripe - (-obj->vector.w / 2 + screen.x)) * obj->sprite->v.w / obj->vector.w) / 256;
					t.pos.y = (int)(
							((int)(y * 256 - W_HEIGHT * 128 + obj->vector.h * 128) * obj->sprite->v.h)
							/ obj->vector.h) / 256;
					color = __get_color_sprite(obj->sprite, t.pos.x, t.pos.y);
					(canva()->pixel(stripe, y, color));
				}
			}
		}
		e = e->next;
	}
}