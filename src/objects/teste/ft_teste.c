/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_teste.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/05 20:08:33 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_object_base.h>


static void	__reander(t_buffer *b)
{
	t_vector start;
	int	y = -1;
	int x;

//	render_point(b);
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
}

t_object	*new_teste(void)
{
	t_object	*ob;

	ob = new_object_instance(sizeof(t_object));
	ob->render = __reander;
	return (ob);
}
