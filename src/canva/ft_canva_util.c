/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canva_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:14:35 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/24 17:03:56 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_canva_util.h>

void	__image(t_sprite *sprite)
{
	int		x;
	int		y;

	y = -1;
	while (++y < sprite->v.h)
	{
		x = -1;
		while (++x < sprite->v.w)
		{
			__pixel(sprite->v.x + x, sprite->v.y + y, \
			__get_color_img(sprite->data, x, y));
		}
	}
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
