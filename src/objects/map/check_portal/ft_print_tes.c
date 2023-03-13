/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:01:43 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/13 20:54:31 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

#define Red(x) printf("\033[41m%c\033[39;49m", x);
#define Orange(x) printf("\033[43m%c\033[39;49m", x);
#define Blue(x) printf("\033[44m%c\033[39;49m", x);
#define Magenta(x) printf("\033[35m%c\033[39;49m", x);
#define Normal(x) printf("\033[39;49m%c\033[39;49m", x);
#define Green(x) printf("\033[42m%c\033[39;49m", x);


void print_test(char **map)
{
	int		x;
	int		y;
	char	c;

	y = -1;
	system("clear");
	while (map[++y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			c = map[y][x];
			if (c == '1')
				Orange(c)
            else if (c == 1)
				Green('A')
            else if (c == 2)
				Blue('B')
             else if (c == 3)
				Red('C')
			else if (c == 'K')
				Magenta(c)
			else
				Normal(c)
			x++;
		}
		printf("\n");
	}
	printf("==========================================\n\033[39;49m");
}