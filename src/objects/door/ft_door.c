/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:20:00 by nprimo            #+#    #+#             */
/*   Updated: 2022/10/14 18:44:32 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>

static int	check_collision(t_vector v)
{
	t_vector	p;

	p = fthis()->player->vector;
	return (collision().rectangular(v, p));
}

static void	__funct_key(int *key, int type_event)
{
	t_vector	v;
	t_door		*door;

	(void) type_event;
	door = (t_door *) this();
	if (key[KEY_SPACE] && !door->is_open)
	{
		if (check_collision(door->vector))
		{
			door->is_open = 1;
			array(scene()->colliders_list)->remove_value(this());
			printf("dor--> player open\n");
		}
	}
}

static void	__updade(void)
{
	t_door	*door;

	door = (t_door *) this();
	if (door->is_open && !check_collision(door->vector) \
	&& ++door->count > 50)
	{
		array(scene()->colliders_list)->add(door);
		door->count = 0;
		door->is_open = 0;
	}
}

static t_sprite	*get_sprite(t_ray ray)
{
	static t_sprite	*sprite;

	(void) ray;
	if (sprite == NULL)
		sprite = engine()->load_sprite("imgs/tester.xpm");
	return (sprite);
}

t_object	*new_door(void)
{
	t_door	*door;

	door = new_object_instance(sizeof(t_door));
	door->type = DOOR;
	door->update = __updade;
	door->collision = __collision_base;
	door->funct_key = __funct_key;
	door->vector = vector(0, 0, W_WIDTH, W_HEIGHT);
	door->get_sprite = get_sprite;
	return ((t_object *) door);
}
