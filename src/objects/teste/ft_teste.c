/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_teste.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/28 19:33:21 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_object_base.h>

static void render_point(t_buffer *b)
{
	t_vector	p;
	int			x;
	int			y;

	p = scene()->player->vector;
	x = ((int) p.x /  GRID_SIZE) * GRID_SIZE;
	y = ((int) p.y /  GRID_SIZE) * GRID_SIZE;
	b->pixel(x, y, 0x1979e6);
}

static void	__reander(t_buffer *b)
{
	t_vector start;

	// start = vector_zero();
	// while (start.y < map()->vector.h)
	// {
	// 	b->line(vector(map()->vector.w - GRID_SIZE, start.y, 0, 0), start, 0);
	// 	start.y += GRID_SIZE;
	// }
	// start = vector_zero();
	// while (start.x < map()->vector.w)
	// {
	// 	b->line(start, vector(start.x, map()->vector.h, 0, 0), 0);
	// 	start.x += GRID_SIZE;
	// }
	render_point(b);
	print_raycast(scene()->player);
}

t_object	*new_teste(void)
{
	t_object	*ob;

	ob = new_object_instance(sizeof(t_object));
	ob->render = __reander;
	return (ob);
}
