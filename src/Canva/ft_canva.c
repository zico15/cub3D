/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canva.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:14:35 by edos-san          #+#    #+#             */
/*   Updated: 2022/09/02 19:42:01 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_canva_util.h>
#include <ft_util.h>

void	__pixel(int x, int y, int color)
{
	char		*dst;
	t_data		*data;

	if (color == COLOR_TRANSPARENT || (x >= W_WIDTH || y >= W_HEIGHT))
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
	b.rectangle_border = __rectangle_border;
	b.line = __print_line;
	return (&b);
}
