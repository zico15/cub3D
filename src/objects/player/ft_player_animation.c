/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_animation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:17:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/03 21:45:25 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_component.h>
#include <ft_player.h>

void __load_animation(t_player *p)
{
	static t_sprites	*animations;
	static char			file[20] = "imgs/IMG/Arma01.xpm";
	static int			i = 0;
	static int			size = 69;

	if (!animations)
	{
		animations = malloc_ob(sizeof(t_sprites));
		p->animation.size = 1;
		animations[0].list = malloc_ob(sizeof(t_sprites *) * size);
		animations[0].size = size;
		while (++i <=  size)
		{
			file[13] = (i / 10) + '0';
			file[14] = (i % 10) + '0';
			animations[0].list[i - 1] = engine()->load_sprite(file);
		}
	}
	p->animation.animations = animations;
	p->animation.size = size;
}