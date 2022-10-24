/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canva_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:34:45 by nprimo            #+#    #+#             */
/*   Updated: 2022/10/24 23:35:46 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_canva_util.h>

void	__rectangle(t_vector v, int color)
{
	int			x;

	v.w += v.x;
	v.h += v.y;
	while (v.y < v.h)
	{
		x = v.x;
		while (x < v.w)
		{
			__pixel(x++, v.y, color);
		}
		v.y++;
	}
}

void	__rectangle_border(t_vector v, int color, int border, int color_border)
{
	int			x;
	t_vector	v_b;

	v.w += v.x;
	v.h += v.y;
	v_b = vector(v.x + border, v.y + border, v.w - border, v.h - border);
	while (v.y < v.h)
	{
		x = v.x;
		while (x < v.w)
		{
			if (x <= v_b.x || x >= v_b.w || (v.y <= v_b.y || v.y >= v_b.h))
				__pixel(x++, v.y, color_border);
			else
				__pixel(x++, v.y, color);
		}
		v.y++;
	}
}

void	__image_resize(t_sprite *sprite, double width, double height)
{
	double	temp_x;
	double	temp_y;
	double	resize_x;
	double	resize_y;
	int		x;
	int		y;

	temp_y = 0;
	y = -1;
	resize_x = ((double) sprite->v.w / width);
	resize_y = ((double) sprite->v.h / height);
	while (++y < (int) height)
	{
		temp_x = 0;
		x = -1;
		while (++x < (int) width)
		{
			__pixel(x, y, __get_color_sprite(sprite, (int) temp_x, temp_y));
			temp_x += resize_x;
		}
		temp_y += resize_y;
	}
}

void	__image_pos(t_sprite *sprite, int x1, int y1)
{
	int		x;
	int		y;

	y = -1;
	while (++y < sprite->v.h)
	{
		x = -1;
		while (++x < sprite->v.w)
		{
			__pixel(x1 + x, y1 + y, \
			__get_color_img(sprite->data, x, y));
		}
	}
}

void	__draw_line(t_vector begin, t_vector end, int color)
{
	int			pixels;
	t_vector	delta;

	delta.x = end.x - begin.x;
	delta.y = end.y - begin.y;
	pixels = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	delta.x /= pixels;
	delta.y /= pixels;
	delta.w = begin.x;
	delta.h = begin.y;
	while (pixels-- > 0)
	{
		(canva())->pixel(delta.w, delta.h, color);
		delta.w += delta.x;
		delta.h += delta.y;
	}
}
