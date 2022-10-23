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

void	__destroy_animation(t_object *ob)
{
	t_animation *a;
	int			i;

	a = ob->animation;
	if (!a)
		return ;
	i = -1;
	while (++i < ob->size_animation)
		free_ob(ob->animation[i].list);
	free_ob(ob->animation);
	ob->animation = NULL;
	ob->size_animation = 0;
}
