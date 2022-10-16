/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:17:41 by ezequeil          #+#    #+#             */
/*   Updated: 2022/10/14 19:01:38 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_player.h>

static void	__collision(t_object *collided)
{
	if (!collided)
		printf("collided: %i\n", collided->type);
}

static void	__render(t_buffer *b)
{
	static t_vector v;

	if (map()->is_print)
		b->rectangle(vector_grid_size(this()->vector, 2, 2), 0xffff00);
}

static void	__update(void)
{
	update_animation_all(this());
}

t_player	*new_player(void)
{
	t_player	*p;

	p = new_object_instance(sizeof(t_player));
	p->type = PLAYER;
	p->funct_key = __funct_key;
	p->funct_mouse = __funct_mouse;
	p->collision = __collision;
	p->vector.angle = 90;
	p->vector.w = 10;
	p->vector.h = 10;
	p->update = __update;
	p->render = __render;
	p->life = 5;
	p->set_position = __set_position;
	__load_animation(p);
	p->sprite = *p->animation[0].list;
	fthis()->player = p;
	return (p);
}
