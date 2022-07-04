/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:31:55 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/04 22:01:27 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

void	__pixel_put_win(int x, int y, int color)
{
	mlx_pixel_put(engine()->mlx, engine()->win, x, y, color);
}
