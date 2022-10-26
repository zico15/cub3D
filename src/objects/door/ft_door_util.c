/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:20:00 by nprimo            #+#    #+#             */
/*   Updated: 2022/10/26 15:34:50 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>

void	__destroy_ob_door(void)
{
	t_door	*door;

	door = (t_door *) this();
	__destroy_ob();
	destroy_sprite(door->sprite_animation);
}

void	__animation_door(t_door *door, t_vector	v)
{
	int			max_1;
	int			max_2;
	int			color;

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
}
