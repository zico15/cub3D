/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/18 10:56:31 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_object_base.h>

void	__load_animation_life(t_object *ob);

static void	mini_map(t_buffer *b, t_vector p, t_vector m)
{
	t_vector	v;
	t_vector	p_rel;
	t_vector	direction;
	t_player	*player;
	double		val;

	player = scene()->player;
	v = vector(p.x * GRID_MIN_SIZE, p.y * GRID_MIN_SIZE, 200, 150);
	b->rectangle_border(m, 0xe5e6e6, 3, 0xdf0707);
	m.x += 3;
	m.y += 3;
	m.w -= 6;
	m.h -= 6;
	map()->sprite->v = m;
	p_rel.x = m.x + 91 - 2 * GRID_MIN_SIZE;
	p_rel.y = m.y + 72 - GRID_MIN_SIZE;
	direction.x = p_rel.x + p.w / 2 + player->dir.x * 10;
	direction.y = p_rel.y + p.h / 2 + player->dir.y * 10;
	b->image_sub(map()->sprite, v);
	b->rectangle(vector(p_rel.x - p.w / 2, p_rel.y - p.h / 2, p.w, p.h), 0xd36a0d);
	b->rectangle(vector(direction.x, direction.y, 2, 2),
		0x00990099);
}

static void	__render(t_buffer *b)
{
	t_vector	p;
	t_sprite	*sprite;

	p = scene()->player->vector;
	mini_map(b, p, this()->vector);
	if (scene()->player->sprite)
		b->image_pos(scene()->player->sprite, 0, 100);
	if (!scene()->player->life)
		return;
	sprite = this()->animation[0].list[5 - scene()->player->life];
	b->image_pos(sprite, this()->vector.x, 156);
}

t_object	*new_menu(void)
{
	t_object	*ob;

	ob = new_object_instance(sizeof(t_object));
	ob->render = __render;
	ob->vector.w = 206;
	ob->vector.h = 156;
	ob->vector.x = engine()->width - ob->vector.w;
	ob->vector.y = 0;
	__load_animation_life(ob);
	return (ob);
}
