/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canva.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:14:35 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/24 23:39:52 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_canva_util.h>
#include <ft_util.h>

void	__image_pos(t_sprite *sprite, int x, int y);
void	__draw_line(t_vector begin, t_vector end, int color);
void	__image_resize(t_sprite *sprite, double width, double height);

t_buffer	*__canva(void)
{
	static t_buffer	b;

	printf("__canva\n");
	b.buffer = mlx_new_image(engine()->mlx, engine()->width, engine()->height);
	b.data.img = b.buffer;
	b.data.addr = mlx_get_data_addr(b.data.img, &b.data.bits_per_pixel, \
	&b.data.line_length, &b.data.endian);
	b.rectangle = __rectangle;
	b.pixel = __pixel;
	b.get_color_img = __get_color_img;
	b.image = __image;
	b.image_sub = __image_sub;
	b.object = __object;
	b.rectangle_border = __rectangle_border;
	b.image_pos = __image_pos;
	b.line = __draw_line;
	b.image_resize = __image_resize;
	return (&b);
}

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

int	__get_color_img(t_data	data, int x, int y)
{
	char		*dst;
	int			color;

	dst = data.addr + (y * data.line_length + x \
	* (data.bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

int	__get_color(void *img, int x, int y)
{
	char		*dst;
	int			color;
	t_data		data;

	data.img = img;
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
	&data.line_length, &data.endian);
	dst = data.addr + (y * data.line_length + x \
	* (data.bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

int	__get_color_sprite(t_sprite *sprite, int x, int y)
{
	char		*dst;
	int			color;

	if (x >= sprite->v.w || y >= sprite->v.h || x < 0 || y < 0)
		return (COLOR_TRANSPARENT);
	dst = sprite->data.addr + (y * sprite->data.line_length + x \
	* (sprite->data.bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}
