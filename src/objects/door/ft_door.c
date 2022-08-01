/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:20:00 by nprimo            #+#    #+#             */
/*   Updated: 2022/08/01 18:04:20 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>

static void	__funct_key(int key, int type_event)
{
	t_vector	p;
	t_vector	v;
	t_door		*door;

	(void) type_event;
	if (key == KEY_SPACE)
	{
		door = (t_door *) this();
		p = fthis()->player->vector;
		v = this()->vector;
		v.x -= 7;
		v.x -= 7;
		v.w += 7;
		v.h += 7;
		door->is_open = colison().rectangular(p, v);
		if (door->is_open)
		{
			array(scene()->colliders_list)->remove_value(this());
			printf("dor--> player open\n");
		}
		printf("door key: %i\n", key);
	}
}

static void	__colison(t_object *collided)
{
	printf("dor--> %i\n", collided->type);
}

static void	__updade(void)
{
	t_door	*door;

	door = (t_door *) this();
	if (!door->is_open)
		return ;
}

static void	__render(t_buffer *b)
{
	t_door	*door;

	door = (t_door *) this();
	if (!door->is_open)
		b->rectangle(this()->vector, 0xee00ff);
	else
	{
		b->rectangle_border(this()->vector, COLOR_TRANSPARENT, \
		3, 0xee00ff);
	}
}

t_object	*new_door(void)
{
	t_door	*door;

	door = new_object_instance(sizeof(t_door));
	door->render = __render;
	door->colison = __colison;
	door->funct_key = __funct_key;
	door->vector = vector(0, 0, W_WIDTH, W_HEIGHT);
	return ((t_object *) door);
}

