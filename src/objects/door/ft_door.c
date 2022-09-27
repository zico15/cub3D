/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:20:00 by nprimo            #+#    #+#             */
/*   Updated: 2022/09/22 21:49:12 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>

static int	check_colison(t_vector v)
{
	t_vector	p;

	p = fthis()->player->vector;
	v.x -= 7;
	v.x -= 7;
	v.w += 7;
	v.h += 7;
	return (colison().rectangular(p, v));
}

static void	__funct_key(int key, int type_event)
{
	t_vector	v;
	t_door		*door;

	(void) type_event;
	door = (t_door *) this();
	if (key == KEY_SPACE && !door->is_open)
	{
		if (check_colison(door->vector))
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
	if (door->is_open && !check_colison(door->vector) \
	&& ++door->count > 50)
	{
		array(scene()->colliders_list)->add(door);
		door->count = 0;
		door->is_open = 0;
	}
}

// static void	__render(t_buffer *b)
// {
// 	t_door	*door;

// 	door = (t_door *) this();
// 	if (!door->is_open)
// 		b->rectangle(this()->vector, 0xee00ff);
// 	else
// 		b->rectangle_border(this()->vector, COLOR_TRANSPARENT, \
// 		3, 0xee00ff);
// }

static t_sprite	*get_sprite(t_ray ray){
	static t_sprite	*sprite;

	(void) ray;
	if (sprite == NULL)
		sprite = engine()->load_sprite("imgs/tester.xpm");
	return sprite;
}

t_object	*new_door(void)
{
	t_door	*door;

	door = new_object_instance(sizeof(t_door));
	door->type = DOOR;
	// door->render = __render;
	door->update = __updade;
	door->colison = __colison_base;
	door->funct_key = __funct_key;
	door->vector = vector(0, 0, W_WIDTH, W_HEIGHT);
	door->get_sprite = get_sprite;
	return ((t_object *) door);
}

