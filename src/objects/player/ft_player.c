/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:17:41 by ezequeil          #+#    #+#             */
/*   Updated: 2022/10/18 10:53:08 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_player.h>

int	__damage_player(double d);

static void	__collision(t_object *collided)
{

}

static void	__render(t_buffer *b)
{
	if (map()->is_print)
		b->rectangle(vector_grid_size(this()->vector, 12, 12), 0xffff00);
	animation().update_all(this());
}

t_object	*new_player(void)
{
	t_player	*p;

	p = new_object_instance(sizeof(t_player));
	p->type = PLAYER;
	p->funct_key = __funct_key;
	p->funct_mouse = __funct_mouse;
	p->collision = __collision;
	p->vector.angle = 90;
	p->vector.w = 20;
	p->vector.h = 20;
	p->render = __render;
	p->life = 5;
	p->damage = __damage_player;
	p->set_position = __set_position;
	p->animation = animation().create(this(), 1);
	(animation()).load_animation("imgs/IMG/Arma00.xpm", 9, &(p->animation[0]), \
	25);
	p->sprite = *p->animation[0].list;
	fthis()->player = p;
	return ((t_object *) p);
}
