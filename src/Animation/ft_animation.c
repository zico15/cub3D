/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:39:12 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/03 21:57:10 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_animation_util.h>

void set_animation(t_object *obj, int i)
{
	int	j;

	if (obj->animation.animations && i < obj->animation.size)
	{
		j = obj->animation.animations[i].index;
		j += 1;
		if (j >= obj->animation.animations[i].size)
		{
			j = 0;
			obj->animation.is_run = obj->animation.animations[i].is_repeat;
		}
		obj->sprite = obj->animation.animations[i].list[j];
		printf("set_animation: %i\n", j);
		obj->animation.animations[i].index = j;
	}
}