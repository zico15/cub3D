/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:11:01 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/08 16:33:02 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_engine_util.h>

static void	__pixel_buffer(t_sprite *buffer, int x, int y, int color)
{
	char		*dst;
	t_data		*data;

	if (color == COLOR_TRANSPARENT)
		return ;
	data = &buffer->data;
	dst = data->addr + (y * data->line_length + x \
	* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	__image_resize_buffer(t_sprite *buffer, t_sprite *sprite)
{
	t_vector	v;
	int			x;
	int			y;

	v.y = 0;
	y = -1;
	v.w = ((double) sprite->v.w / buffer->v.w);
	v.h = ((double) sprite->v.h / buffer->v.h);
	while (++y < buffer->v.h)
	{
		v.x = 0;
		x = -1;
		while (++x < buffer->v.w)
		{
			__pixel_buffer(buffer, x, y, \
			__get_color_sprite(sprite, (int) v.x, (int) v.y));
			v.x += v.w;
		}
		v.y += v.h;
	}
}
