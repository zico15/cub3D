/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_barrel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/26 18:05:11 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_object_base.h>

static void	__render(t_buffer *b)
{
	if (map()->is_print)
		b->rectangle(vector_grid_size(this()->vector, 12, 12), 0x24799e);
	animation().update_all(this());
	if (this()->life <= 0 && this()->animation->index == 19)
		scene()->remove_object(this());
}

static void	key(char *key, int event)
{
	if (event == EVENT_CLICK && key[KEY_SPACE])
		this()->animation->is_run = 1;
}

static void	__attack_barrel(t_object	*ob)
{
	t_object	*tmp;

	if (!ob || ob == this())
		return ;
	if (vector_distance(ob->vector, this()->vector) < 2 \
	&& ob->damage)
	{
		tmp = this();
		fthis()->object = ob;
		ob->damage(1);
		fthis()->object = tmp;
	}
}

static int	__damage(double d)
{
	t_element	*e;
	void		*list;

	this()->life -= d;
	if (this()->life <= 0)
	{
		this()->animation->is_run = 1;
		__attack_barrel((t_object *) scene()->player);
		list = fthis()->array;
		e = array(scene()->free_objects)->begin;
		while (e)
		{
			__attack_barrel((t_object *) e->value);
			e = e->next;
		}
		fthis()->array = list;
	}
	return (this()->life <= 0);
}

t_object	*new_barrel(void)
{
	t_object		*ob;

	ob = new_object_instance(sizeof(t_object));
	ob->type = OBJECT;
	ob->life = 2;
	ob->damage = __damage;
	ob->render = __render;
	ob->funct_key = key;
	ob->collision = __collision_base;
	ob->animation = animation().create(ob, 1);
	(animation()).load_animation("imgs/barrel/frame-00.xpm", 20, \
	&(ob->animation[0]), 20);
	ob->sprite = *ob->animation->list;
	return ((t_object *) ob);
}
