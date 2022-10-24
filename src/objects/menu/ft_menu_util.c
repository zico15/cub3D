/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/24 21:56:29 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_object_base.h>

void	__load_animation_life(t_object *ob)
{
	static t_animation	*animations;
	static char			file[20] = "imgs/life/life00.xpm";
	static int			i = 0;
	static int			size = 5;

	i = -1;
	animations = malloc_ob(sizeof(t_animation));
	animations[0].size = 1;
	animations[0].list = malloc_ob(sizeof(t_sprite *) * size);
	animations[0].size = size;
	animations[0].time_delay = 60;
	while (++i < size)
	{
		file[14] = (i / 10) + '0';
		file[15] = (i % 10) + '0';
		animations[0].list[i] = engine()->load_sprite(file);
	}
	ob->size_animation = 1;
	ob->animation = animations;
}
