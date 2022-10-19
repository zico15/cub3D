/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/18 16:25:20 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_object_base.h>


static void	load_animation(t_object *p)
{
	static t_animation	*animations;
	static char			file[25] = "imgs/barrel/frame-00.xpm";
	static int			i = 0;
	static int			size = 20;

	i = -1;
	animations = malloc_ob(sizeof(t_animation));
	animations[0].size = 1;
	animations[0].list = malloc_ob(sizeof(t_sprite *) * size);
	animations[0].size = size;
	animations[0].time_delay = 25;
	while (++i < size)
	{
		file[18] = (i / 10) + '0';
		file[19] = (i % 10) + '0';
		animations[0].list[i] = engine()->load_sprite(file);
	}
	animations->is_repeat = 0;
	p->size_animation = 1;
	p->animation = animations;
}


static void	__render(t_buffer *b)
{
	if (map()->is_print)
		b->rectangle(vector_grid_size(this()->vector, 12, 12), 0x24799e);
	animation().update_all(this());
}

static void key(int *key, int event)
{

	if (event == EVENT_CLICK && key[KEY_SPACE])
		this()->animation->is_run = 1;
}

t_object	*new_barrel(void)
{
	t_object		*ob;

	ob = new_object_instance(sizeof(t_object));
	ob->type = OBJECT;
	ob->render = __render;
	ob->funct_key = key;
	ob->collision = __collision_base;
	ob->animation = animation().create(ob, 1);
	animation().load_animation("imgs/barrel/frame-00.xpm", 20, \
	&(ob->animation[0]), 20);
	ob->sprite = *ob->animation->list;
	return ((t_object *) ob);
}
