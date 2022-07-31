/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canva.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:14:35 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/31 19:49:16 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_canva_util.h>

void	__pixel(int x, int y, int color)
{
	char		*dst;
	t_data		*data;

	if (color == COLOR_TRANSPARENT)
		return ;
	data = &canva()->data;
	dst = data->addr + (y * data->line_length + x \
	* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	__get_color_imge(t_data	data, int x, int y)
{
	char		*dst;
	int			color;

	dst = data.addr + (y * data.line_length + x \
	* (data.bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

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

t_buffer	*__canva(void)
{
	static t_buffer	b;

	b.buffer = mlx_new_image(engine()->mlx, engine()->width, engine()->height);
	b.data.img = b.buffer;
	b.data.addr = mlx_get_data_addr(b.data.img, &b.data.bits_per_pixel, \
	&b.data.line_length, &b.data.endian);
	b.rectangle = __rectangle;
	b.pixel = __pixel;
	b.get_color_imge = __get_color_imge;
	b.image = __image;
	b.image_sub = __image_sub;
	b.object = __object;
	return (&b);
}


