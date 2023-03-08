/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_portal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/08 14:47:41 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_check.h>

static void	__collision(t_object *collided)
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

static	int	__damage(double d)
{
	(void) d;
	printf("d: %f\n", d);
	return (0);
}

t_object	*new_portal(void)
{
	t_portal		*portal;

	portal = new_object_instance(sizeof(t_portal));
	portal->type = WALL;
	portal->damage = __damage;
	portal->funct_key = key;
	portal->collision = __collision;
	portal->get_sprite = get_sprite;
	return ((t_object *) portal);
}
