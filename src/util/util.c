/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:01:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/23 20:24:51 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <stdio.h>

void	__destroy_element_object(t_element	*e)
{
	t_object	*o;
	void		*list;
	t_object	*temp;

	o = (t_object *) e->value;
	temp = fthis()->object;
	list = fthis()->array;
	fthis()->object = o;
	if (o && o->destroy)
		o->destroy();
	free_ob(e->key);
	free_ob(e->value);
	free_ob(e);
	fthis()->object = temp;
	fthis()->array = list;
}

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

int	**baffer_int(void)
{
	static int	i[20000][20000];

	return ((int **) i);
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
	static char *type[8] = {"OBJECT", "SCENE", "MAP", "PLAYER", \
	"WALL", "DOOR", "ENEMY", "COLLECTABLE"};

	return (type[object_type]);
}
