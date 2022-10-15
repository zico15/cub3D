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
	t_player	*p;
	t_vector	v;

	p = scene()->player;
	v = vector((p->vector.x * GRID_SIZE) - 3, (p->vector.y * GRID_SIZE) - 3, 6, 6);
	b->rectangle(v, 0xffff00);
}

static void	__update(void)
{
	t_player	*p;

	p = scene()->player;
	if (p->animation.is_run && (p->animation.time < now()))
	{
		if (++p->animation.index >= p->animation.animations->size)
		{	
			p->animation.index = 0;
			p->animation.is_run = 0;
		}
		p->animation.time = now() + 60;
		p->sprite = p->animation.animations->list[p->animation.index];
	}
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
	p->set_position = __set_position;
	__load_animation(p);
	p->sprite = *p->animation.animations->list;
	fthis()->player = p;
	return (p);
}
