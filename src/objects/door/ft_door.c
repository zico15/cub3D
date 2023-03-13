/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:20:00 by nprimo            #+#    #+#             */
/*   Updated: 2023/03/13 20:52:17 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>

void	__destroy_ob_door(void);
void	__animation_door(t_door *door, t_vector	v);

static void	__funct_key(char *key, int event)
{
	t_door		*door;
	int			distance;

	if (key[KEY_E] && event == EVENT_CLICK)
	{
		door = (t_door *) this();
		distance = vector_distance(scene()->player->vector, this()->vector);
		if (distance <= 1)
		{
			door->is_open = !door->is_open;
			door->is_run = 1;
			array(scene()->colliders_list)->remove_value(this());
		}
	}
}

static	void	__updade(void)
{
	t_door		*door;

	door = (t_door *) this();
	if (door->is_run && now() > door->time)
	{
		door->time = now() + door->delay;
		__animation_door(door, door->sprite->v);
		door->count = 0;
		door->is_run = !(door->count_max == 31 || door->count_max == -1);
		if (!door->is_run)
		{
			if (door->is_open)
				door->collision = NULL;
			else
				door->collision = __collision_base;
		}
	}
}

static t_sprite	*get_sprite(t_ray ray)
{
	t_door	*door;

	door = (t_door *) this();
	(void) ray;
	return (door->sprite_animation);
}

static void	__render(t_buffer *b)
{
	t_door	*door;

	door = (t_door *) this();
	if (map()->is_print && door->collision)
		b->rectangle(vector_grid(door->vector), 0xee82ee);
}

t_object	*new_door(void)
{
	t_door			*door;

	door = new_object_instance(sizeof(t_door));
	door->type = DOOR;
	door->update = __updade;
	door->collision = __collision_base;
	door->funct_key = __funct_key;
	door->get_sprite = get_sprite;
	door->render = __render;
	door->delay = 0.05;
	door->destroy = __destroy_ob_door;
	door->sprite = engine()->load_sprite("imgs/door.xpm");
	door->sprite_animation = copy_sprite(door->sprite);
	door->count_max = 1;
	return ((t_object *) door);
}
