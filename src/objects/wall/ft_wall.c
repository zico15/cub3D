/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/14 19:08:21 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_check.h>

static void	__collision(t_object *collided)
{
	(void) collided;
}

static void	__reander(t_buffer *b)
{
	b->rectangle(vector_grid(this()->vector), 0x0000FF00);
}

static t_sprite	*get_sprite(t_ray ray)
{
	static t_sprite	*sprite;

	(void) ray;
	if (sprite == NULL)
		sprite = engine()->load_sprite("imgs/wall_s.xpm");
	return (sprite);
}

t_object	*new_wall(void)
{
	t_object		*wall;

	wall = new_object_instance(sizeof(t_object));
	wall->type = WALL;
	wall->render = __reander;
	wall->collision = __collision;
	wall->get_sprite = get_sprite;
	return (wall);
}
