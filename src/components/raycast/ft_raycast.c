/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:57:49 by ezequeil          #+#    #+#             */
/*   Updated: 2022/07/04 22:27:08 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

void	print_raycast(t_player *p)
{
	int	x;
	int	y;
	int	x_p;
	int	max_x;
	int	x_m;

	x = p->vector.x + (32 / 2);
	x_p = p->vector.x + (32 / 2);
	y = p->vector.y + (32 / 2);
	x_m = 0;
	max_x = x + 50;
	while (x < max_x)
	{
		(render()).pixel_put_win(x, y, 0x00990099);
		(render()).pixel_put_win((x_p - x_m), y, 0x00990099);
		x++;
		x_m++;
	}
}
