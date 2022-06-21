/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:31:55 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/20 23:14:56 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

static void	__pixel_put_rec(t_data *data, int color, t_vector vector)
{
	int	x;

	vector.w += vector.x;
	vector.h += vector.y;
	while (vector.y < vector.h)
	{
		x = vector.x;
		while (x < vector.w)
		{
			(render().pixel_put)(data, x++, vector.y, color);
		}
		vector.y++;
	}
}

static void	__pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	__print(t_object *o)
{
	if (o && o->img)
		mlx_put_image_to_window(engine()->mlx, engine()->win, \
		o->img, o->vector.x, o->vector.y);
}

t_render	render(void)
{
	static t_render	r = {__print, __pixel_put, __pixel_put_rec};

	return (r);
}
