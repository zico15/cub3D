/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canva_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:14:35 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/14 18:35:07 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_canva_util.h>

void	__image(t_sprite *sprite)
{
	t_data	data;
	int		x;
	int		y;

	data.img = sprite->img;
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
	&data.line_length, &data.endian);
	y = -1;
	while (++y < sprite->v.h)
	{
		x = -1;
		while (++x < sprite->v.w)
		{
			__pixel(sprite->v.x + x, sprite->v.y + y, \
			__get_color_img(data, x, y));
		}
	}
}

static t_vector	get_vector_sub(t_vector img, t_vector sub)
{
	sub.w += sub.x;
	sub.h += sub.y;
	if (sub.w > (img.w))
		sub.w = img.w;
	if (sub.h > (img.h))
		sub.h = img.h;
	sub.x = sub.x * (sub.x >= 0);
	sub.y = sub.y * (sub.y >= 0);
	return (sub);
}

void	__image_sub(t_sprite *sprite, t_vector sub)
{
	static t_data	data;
	t_vector		temp;
	static double	x;
	static double	y;

	data.img = sprite->img;
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
	&data.line_length, &data.endian);
	temp.y = -1;
	while (++temp.y < sprite->v.h && --sub.h > 0)
	{
		temp.x = -1;
		temp.w = sub.w;
		while (++temp.x < sprite->v.w && --temp.w > 0)
		{
			x = temp.x + sub.x;
			y = temp.y + sub.y;
			if (x >= 0 && y >= 0)
				__pixel(sprite->v.x + temp.x, sprite->v.y + \
				temp.y, __get_color_img(data, x, y));
		}
	}
}

void	__object(t_object *ob)
{
	if (ob->sprite)
		__image(ob->sprite);
}
