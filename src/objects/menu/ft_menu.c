/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/14 18:51:34 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_object_base.h>

static void	mini_map(t_buffer *b, t_vector p, t_vector m)
{
	t_vector	v;
	t_vector	p_rel;
	t_vector	direction;
	double		val;

	v = vector(p.x * GRID_MIN_SIZE, p.y * GRID_MIN_SIZE, 200, 150);
	b->rectangle_border(m, 0xe5e6e6, 3, 0xdf0707);
	m.x += 3;
	m.y += 3;
	m.w -= 6;
	m.h -= 6;
	map()->sprite->v = m;
	p_rel.x = m.x + 91;
	p_rel.y = m.y + 72;
	p_rel.angle = p.angle;
	val = M_PI / 180;
	direction.y = p_rel.y - (20 * sin(p.angle * val));
	direction.x = p_rel.x + (20 * cos(p.angle * val));
	b->image_sub(map()->sprite, v);
	b->rectangle(vector(p_rel.x, p_rel.y, 10, 10), 0xd36a0d);
	b->rectangle(vector(direction.x + 5 - 1, direction.y + 5 - 1, 2, 2),
		0x00990099);
}

static void	__reander(t_buffer *b)
{
	t_vector	p;

	p = fthis()->player->pos;
	p.x = ((p.x - (p.w / 2) - GRID_SIZE) / GRID_SIZE) - 1;
	p.y = ((p.y - (p.h / 2) - GRID_SIZE) / GRID_SIZE);
	mini_map(b, p, this()->vector);
	if (0 && fthis()->player->sprite)
		b->image(fthis()->player->sprite);
}

t_object	*new_menu(void)
{
	t_object	*ob;

	ob = new_object_instance(sizeof(t_object));
	ob->render = __reander;
	ob->vector.w = 206;
	ob->vector.h = 156;
	ob->vector.x = engine()->width - ob->vector.w;
	ob->vector.y = 0;
	return (ob);
}
