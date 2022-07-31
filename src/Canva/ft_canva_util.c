/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canva_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:14:35 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/31 22:33:59 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_canva_util.h>

void	__image(t_vector v, void *img)
{
	t_data	data;
	int		x;
	int		y;

	data.img = img;
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
	&data.line_length, &data.endian);
	y = -1;
	while (++y < v.h)
	{
		x = -1;
		while (++x < v.w)
		{
			__pixel(v.x + x, v.y + y, \
			__get_color_imge(data, x, y));
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

void	__image_sub(t_vector v, void *img, t_vector sub)
{
	t_data	data;
	int		x;
	int		y;
	int		w;

	data.img = img;
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
	&data.line_length, &data.endian);
	y = -1;
	while (++y < v.h && --sub.h > 0)
	{
		x = -1;
		w = sub.w;
		while (++x < v.w && --w > 0)
		{
			__pixel(v.x + x, v.y + y, \
			__get_color_imge(data, x + sub.x, y + sub.y));
		}
	}
}

void	__object(t_object *ob)
{
	if (ob->img)
		__image(ob->vector, ob->img);
}



