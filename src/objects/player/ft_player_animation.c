/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_animation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:17:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/14 19:02:07 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_player.h>

void	__load_animation(t_player *p)
{
	static t_animation	*animations;
	static char			file[20] = "imgs/IMG/Arma01.xpm";
	static int			i = 0;
	static int			size = 9;

	i = 0;
	animations = malloc_ob(sizeof(t_animation));
	animations[0].size = 1;
	animations[0].list = malloc_ob(sizeof(t_sprite *) * size);
	animations[0].size = size;
	animations[0].time_delay = 25;
	while (++i <= size)
	{
		file[13] = (i / 10) + '0';
		file[14] = (i % 10) + '0';
		animations[0].list[i - 1] = engine()->load_sprite(file);
	}
	animations->is_repeat = 1;
	p->size_animation = 1;
	p->animation = animations;
}
