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

void	__triangle(t_vector pos, t_vector dir, t_vector perp_dir, int color)
{
	int			width;
	t_vector	direction_point;
	t_vector	base_left;
	t_vector	base_right;

	width = 5;
	direction_point = vector(
			pos.x + dir.x * width * 2,
			pos.y + dir.y * width * 2,
			1, 1);
	base_left = vector(
			pos.x - perp_dir.x * width,
			pos.y - perp_dir.y * width,
			1, 1);
	base_right = vector(
			pos.x + perp_dir.x * width,
			pos.y + perp_dir.y * width,
			1, 1);
	__draw_line(direction_point, base_left, color);
	__draw_line(direction_point, base_right, color);
	__draw_line(base_right, base_left, color);
}
