/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:17:41 by ezequeil          #+#    #+#             */
/*   Updated: 2023/01/13 22:36:32 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_player.h>

int	__damage_player(double d);

static void	__render(t_buffer *b)
{
	(void) b;
	animation().update_all(this());
}

t_object	*new_player(void)
{
	t_player	*p;

	p = new_object_instance(sizeof(t_player));
	p->type = PLAYER;
	p->funct_key = __funct_key;
	p->funct_mouse = __funct_mouse;
	p->vector.angle = 90;
	p->life = 5;
	p->vector.w = 20;
	p->vector.h = 20;
	p->render = __render;
	p->damage = __damage_player;
	p->set_position = __set_position;
	p->animation = animation().create(this(), 1);
	(animation()).load_animation("imgs/IMG/Arma00.xpm", 9, &(p->animation[0]), \
	25);
	p->sprite = *p->animation[0].list;
	fthis()->player = p;
	return ((t_object *) p);
}
