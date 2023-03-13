/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_pont.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:03:31 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/13 15:32:40 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_check.h>


t_vector close_map(char **map, char open, char close)
{
	int			x;
	int			y;
	t_vector 	pont;

	y = -1;
	pont = vector(-1, -1, -1, -1);
	while (map[++y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			if (map[y][x] == open)
				map[y][x] = close;
			if (pont.x == -1 && pont.y == -1 && map[y][x] == '0')
				pont = vector(x, y, 0, 0);
			x++;
		}
	}
	return (pont);
}