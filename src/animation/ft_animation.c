/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:39:12 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/14 18:19:37 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

void update_animation(t_object *ob, int animation)
{
	int i;

	i = animation;
	if (!ob->animation)
		return;
	if (ob->animation[i].is_run && (ob->animation[i].time < now()))
	{
		if (++ob->animation[i].index >= ob->animation[i].size)
		{	
			ob->animation[i].index = 0;
			ob->animation[i].is_run = ob->animation[i].is_repeat;
		}
		ob->animation[i].time = now() + ob->animation[i].time_delay;
		ob->sprite = ob->animation[i].list[ob->animation[i].index];
	}
}

void update_animation_all(t_object *ob)
{
	int	i;

	i = -1;
	while (++i < ob->size_animation)
		update_animation(ob, i);
}

