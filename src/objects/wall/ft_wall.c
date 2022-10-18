/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/18 14:51:51 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_check.h>


static void	__load_animation(t_object *ob)
{
	t_animation	*animations;
	

	animations = malloc_ob(sizeof(t_animation));
	animations[0].list = malloc_ob(sizeof(t_sprite *) * 4);
	animations[0].size = 4;
	animations->list[0] = engine()->load_sprite("imgs/stone2.xpm");
	animations->list[1] = engine()->load_sprite("imgs/wall_s.xpm");
	animations->list[2] = engine()->load_sprite("imgs/wall.xpm");
	animations->list[3] = engine()->load_sprite("imgs/wall_w.xpm");
	ob->size_animation = 1;
	ob->animation = animations;
}

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
	return (this()->animation->list[ray.face_dir]);
}

t_object	*new_wall(void)
{
	t_object		*wall;

	wall = new_object_instance(sizeof(t_object));
	wall->type = WALL;
	wall->render = __render;
	wall->collision = __collision;
	wall->get_sprite = get_sprite;
	__load_animation(wall);
	return (wall);
}
