/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:20:00 by nprimo            #+#    #+#             */
/*   Updated: 2022/10/24 20:57:01 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>

void	__destroy_ob_door(void);

static void	__funct_key(char *key, int event)
{
	t_door		*door;
	int			distance;

	if (key[KEY_E] && event == EVENT_CLICK)
	{
		door = (t_door *) this();
		distance = vector_distance(scene()->player->vector, this()->vector);
		printf("distance: %i\n", distance);
		if (distance <= 1)
		{
			door->is_open = !door->is_open;
			door->is_run = 1;
			array(scene()->colliders_list)->remove_value(this());
			printf("dor--> player open\n");
		}
	}
}

static	void	__updade(void)
{
	t_door		*door;
	t_vector	v;
	int			color;
	int			max_1;
	int			max_2;

	door = (t_door *) this();
	if (door->is_run && ++door->count > 5)
	{
		v = door->sprite->v;
		max_1 = (v.w / 2) - (door->count_max * 5);
		max_2 = (v.w / 2) + (door->count_max * 5);
		v.y = -1;
		while (++v.y < v.h && door->count_max < 31)
		{
			v.x = -1;
			while (++v.x < v.w)
			{
				color = COLOR_TRANSPARENT;
				if (v.y < 70 || v.x < max_1 || v.x > max_2 || !door->count_max)
					color = __get_color_sprite(door->sprite, v.x, v.y);
				pixel_put_sprite(door->sprite_animation, v.x, \
				v.y, color);
			}
		}
		if (door->is_open && door->count_max < 31)
			door->count_max++;
		else if (!door->is_open && door->count_max > -1)
			door->count_max--;
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
	door->destroy = __destroy_ob_door;
	door->sprite = engine()->load_sprite("imgs/door.xpm");
	door->sprite_animation = copy_sprite(door->sprite);
	door->count_max = 1;
	return ((t_object *) door);
}
