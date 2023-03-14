/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:40:47 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/13 20:56:35 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_check.h>

static void copy_data(char **temp, char 	**copy)
{
    int     x;
    int     y;
    
    y = -1;
    while (temp[++y])
	{
		x = -1;
    
		while (temp[y][++x])
        {
            if (temp[y][x] == '\t' || temp[y][x] == '\n')
                temp[y][x] = ' ';
			copy[y + 1][x + 1] = temp[y][x];
        }
	}
}

static char **copy_map_all(char **temp, int h, int w, t_map *map)
{
	char 	**copy;
	int		y;
	int 	x;

	y = -1;
    h++;
    w++;
	copy = malloc_ob(sizeof(char *) * (h + 2));
	while (++y <= h)
	{
		copy[y] = malloc_ob(sizeof(char) * w + 1);
		x = -1;
		while (++x < w)
			copy[y][x] = ' ';
	}
	map->grid_width = w + 1;
	map->grid_height = h + 1;
	copy[y] = 0;
    copy_data(temp, copy);
	return (copy);
}
char **copy_map(char **temp, t_map *map)
{
    int h;
    int w;
    int s;

    h = -1;
    w = 0;
    while (temp[++h])
	{
		s = string().size(temp[h]);
        if (w < s)
            w = s;
	}
    return (copy_map_all(temp, h, w, map));
}