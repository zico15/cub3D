/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/03 19:30:59 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_check.h>

void	__collision(t_object *collided)
{
	(void) collided;
}

static t_sprite	*get_sprite(t_ray ray)
{
	return (map()->sprits_wall[ray.face_dir]);
}

static void	key(char *key, int event)
{
	if (event == EVENT_CLICK && key[KEY_SPACE])
		printf("ok\n");
}


t_object	*new_wall(void)
{
	t_object		*wall;

	wall = new_object_instance(sizeof(t_object));
	wall->type = WALL;
	wall->funct_key = key;
	wall->collision = __collision;
	wall->get_sprite = get_sprite;
	return (wall);
}
