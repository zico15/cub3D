/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:39:12 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/27 14:43:43 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

void	__destroy_animation(t_object *ob)
{
	t_animation	*a;
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

void	__destroy_animation_size(t_animation	*a, int size)
{
	int			i;

	if (!a)
		return ;
	i = -1;
	while (++i < size)
		free_ob(a[i].list);
	free_ob(a);
}
