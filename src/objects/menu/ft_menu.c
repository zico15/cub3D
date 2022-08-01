/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/01 17:08:06 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_object_base.h>

static void	mini_map(t_buffer *b, t_vector p, t_vector m)
{
	t_vector	v;

	v = vector(p.x * GRID_MIN_SIZE, p.y * GRID_MIN_SIZE, 200, 150);
	b->rectangle_border(m, 0xe5e6e6, 3, 0xdf0707);
	m.x += 3;
	m.y += 3;
	m.w -= 6;
	m.h -= 6;
	b->image_sub(m, map()->img, v);
	b->rectangle(vector(m.x + 95, m.y + 75, 10, 10), 0xd36a0d);
}

static void	__reander(t_buffer *b)
{
	t_vector	p;

	p = fthis()->player->vector;
	p.x = ((p.x - p.w) / GRID_SIZE) - 1;
	p.y = ((p.y - p.h) / GRID_SIZE);
	mini_map(b, p, this()->vector);
}

t_object	*new_menu(void)
{
	t_object	*ob;

	ob = new_object_instance(sizeof(t_object));
	ob->render = __reander;
	ob->vector.w = 206;
	ob->vector.h = 156;
	ob->vector.x = engine()->width - ob->vector.w - 3;
	ob->vector.y = 0;
	return (ob);
}
