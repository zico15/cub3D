/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <ede-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:01:01 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/12 17:42:44 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <stdio.h>

double	now(void)
{
	struct timeval	now;
	double			now_msec;

	if (gettimeofday(&now, NULL) == 0)
		now_msec = now.tv_sec * 1000 + now.tv_usec / 1000;
	else
		now_msec = 0;
	return (now_msec);
}

struct timeval	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now);
}

int	random_number(int min_num, int max_num)
{
	int	low_num;
	int	hi_num;

	low_num = 0;
	hi_num = 0;
	if (min_num < max_num)
	{
		low_num = min_num;
		hi_num = max_num + 1;
	}
	else
	{
		low_num = max_num + 1;
		hi_num = min_num;
	}
	srand(now());
	return ((rand() % (hi_num - low_num)) + low_num);
}

char	*get_type_str(t_type object_type)
{
	static char	*type[8] = {"OBJECT", "SCENE", "MAP", "PLAYER", \
	"WALL", "DOOR", "ENEMY", "COLLECTABLE"};

	return (type[object_type]);
}
