/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/24 21:46:42 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_check.h>

static void	__collision(t_object *collided)
{
	(void) collided;
}

static void	__render(t_buffer *b)
{
	if (map()->is_print)
		b->rectangle(vector_grid(this()->vector), 0x0000FF00);
}

static t_sprite	*get_sprite(t_ray ray)
{
	return (map()->sprits_wall[ray.face_dir]);
}

t_object	*new_wall(void)
{
	t_object		*wall;

	wall = new_object_instance(sizeof(t_object));
	wall->type = WALL;
	wall->render = __render;
	wall->collision = __collision;
	wall->get_sprite = get_sprite;
	return (wall);
}
