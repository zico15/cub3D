/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_portal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/13 20:57:57 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_check.h>

void	__destroy_ob_portal(void);
void	__creat_portal(t_portal *portal, t_face face_dir);
void	__destroy_portal(t_portal *portal);

static void	__collision(t_object *collided)
{
	t_portal	*portal;

	portal = (t_portal *) this();
	if (collided && collided->type == PLAYER)
	{
		if (!portal->next)
		{
			__destroy_portal(portal);
			return ;
		}
		fthis()->object = collided;
		collided->set_position(portal->next_position);
		printf("=======================\npx> %f py: %f", portal->vector.x, \
		portal->vector.y);
		printf("	x> %f y: %f\n", portal->next->next_position.x, \
		portal->next->next_position.y);
		printf("x> %f y: %f", portal->next_position.x, \
		portal->next_position.y);
		printf("	ppx> %f ppxy: %f\n", scene()->player->vector.x, \
		scene()->player->vector.y);
		fthis()->object = (t_object *) portal;
	}
}

static t_sprite	*__animation__portal(t_portal	*portal)
{
	t_sprite	*wall;

	if (now() > portal->animation->time)
	{
		if (++portal->animation->index >= portal->animation->size)
			portal->animation->index = 0;
		wall = map()->sprits_wall[portal->face];
		if (!portal->sprits_wall[portal->face])
			portal->sprits_wall[portal->face] = \
			engine()->new_sprite(wall->v.w, wall->v.h);
		portal->sprite = portal->sprits_wall[portal->face];
		(canva())->image_resize_buffer(portal->sprite, wall);
		(canva())->image_resize_buffer(portal->sprite, \
		portal->animation->list[portal->animation->index]);
		portal->animation->time = now() + 50;
	}
	return (portal->sprits_wall[portal->face]);
}

static t_sprite	*get_sprite(t_ray ray)
{
	t_portal	*portal;
	t_sprite	*wall;

	portal = (t_portal *) this();
	if (portal->sprits_wall[ray.face_dir])
		return (__animation__portal(portal));
	wall = map()->sprits_wall[ray.face_dir];
	if (portal->action)
	{
		__creat_portal(portal, ray.face_dir);
		return (portal->sprite);
	}
	return (wall);
}

static void	key(char *key, int event)
{
	if (event == EVENT_CLICK && key[KEY_SPACE])
		printf("ok\n");
}

void print_test(char **map);

static	int	__damage(double d)
{
	t_portal		*portal;
	static t_portal	*portal_select;

	portal = (t_portal *) this();
	(void) d;
	if (portal->action == 0)
	{
		__destroy_portal(portal_select);
		portal_select = portal;
		portal->action = 1;
		portal->time_action = now() + 50;
		printf("portal->actio: %i\n", portal->action);
		print_test(map()->maps);
	}
	return (0);
}

t_object	*new_portal(void)
{
	t_portal		*portal;

	portal = new_object_instance(sizeof(t_portal));
	portal->type = WALL;
	portal->action = 0;
	portal->damage = __damage;
	portal->funct_key = key;
	portal->collision = __collision;
	portal->get_sprite = get_sprite;
	portal->animation = animation().create((t_object *) portal, 1);
	(animation()).load_animation("imgs/portal/portal_00.xpm", 15, \
	&(portal->animation[0]), 15);
	return ((t_object *) portal);
}
