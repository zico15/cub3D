/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:22:21 by nprimo            #+#    #+#             */
/*   Updated: 2022/10/25 16:16:39 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

t_sprite	*new_sprite(int w, int h)
{
	t_sprite	*s;

	s = malloc_ob(sizeof(t_sprite));
	s->v.w = w;
	s->v.h = h;
	s->img = image().new(w, h);
	s->data.img = s->img;
	s->data.addr = mlx_get_data_addr(s->data.img, &s->data.bits_per_pixel, \
	&s->data.line_length, &s->data.endian);
	return (s);
}

t_sprite	*copy_sprite(t_sprite	*sprite)
{
	t_sprite	*s;
	int			x;
	int			y;

	s = new_sprite(sprite->v.w, sprite->v.h);
	y = -1;
	while (++y < sprite->v.h)
	{
		x = -1;
		while (++x < sprite->v.w)
		{
			pixel_put_sprite(s, x, y, \
			__get_color_sprite(sprite, x, y));
		}
	}
	return (s);
}

void	pixel_put_sprite(t_sprite *sprite, int x, int y, int color)
{
	char		*dst;

	dst = sprite->data.addr + (y * sprite->data.line_length + x \
	* (sprite->data.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	destroy_sprite(t_sprite *sprite)
{
	if (!sprite)
		return ;
	mlx_destroy_image(engine()->mlx, sprite->img);
	free_ob(sprite);
}
