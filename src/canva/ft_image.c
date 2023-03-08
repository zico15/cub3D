/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:11:01 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/08 15:34:36 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_engine_util.h>

static void	__pixel_put(void *img, int x, int y, int color)
{
	char		*dst;
	t_data		data;

	data.img = img;
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
	&data.line_length, &data.endian);
	dst = data.addr + (y * data.line_length + x * (data.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	__pixel_put_rec(void *img, t_vector vector, int color)
{
	int			x;

	vector.w += vector.x;
	vector.h += vector.y;
	while (vector.y < vector.h)
	{
		x = vector.x;
		while (x < vector.w)
		{
			__pixel_put(img, x++, vector.y, color);
		}
		vector.y++;
	}
}

static void	__print_txt(char *str, t_vector v, int color)
{
	mlx_string_put(engine()->mlx, engine()->win, \
	v.x, v.y, color, str);
}

static void	*__new_img(int w, int h)
{
	void	*img;

	img = mlx_new_image(engine()->mlx, w, h);
	__pixel_put_rec(img, vector(0, 0, w, h), COLOR_TRANSPARENT);
	return (img);
}

t_image	image(void)
{
	static t_image	r = {__pixel_put_rec, __pixel_put, \
	__print_txt, __new_img};

	return (r);
}
