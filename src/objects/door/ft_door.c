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
	if (key[KEY_SPACE])
	{
		door->is_open = !door->is_open;
		door->is_run = 1;
		printf("door[KEY_SPACE]\n");
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
	t_door		*door;
	t_vector	v;
	int			color;
	int			max_1, max_2;

	door = (t_door *) this();
	if (door->is_run && ++door->count > 5)
	{
		v = door->sprite->v;
		max_1 =  (v.w / 2) - (door->count_max * 5);
		max_2 =  (v.w / 2) + (door->count_max * 5);
		v.y = -1;
		while (++v.y < v.h && door->count_max < 31)
		{
			v.x = -1;
			while (++v.x < v.w)
			{	
				color = COLOR_TRANSPARENT;
				if(v.y < 70 || v.x < max_1 || v.x > max_2 || !door->count_max)
					color = __get_color_sprite(door->sprite, v.x, v.y);
				pixel_put_sprite(door->sprite_animation, v.x, \
				v.y, color);
			}
		}
		printf("animation: %i [%i]\n", door->count_max, door->is_open);
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
	return (door->sprite_animation);
}

t_object	*new_door(void)
{
	t_door			*door;
	static t_sprite	*sprite;

	door = new_object_instance(sizeof(t_door));
	if (sprite == NULL)
		sprite = engine()->load_sprite("imgs/door.xpm");
	door->type = DOOR;
	door->update = __updade;
	door->collision = __collision_base;
	door->funct_key = __funct_key;
	door->vector = vector(0, 0, W_WIDTH, W_HEIGHT);
	door->get_sprite = get_sprite;
	door->sprite = sprite;
	door->sprite_animation = copy_sprite(sprite);
	door->count_max = 1;
	return ((t_object *) door);
}
