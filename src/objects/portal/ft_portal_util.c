/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_portal_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/08 17:54:06 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_check.h>

void	__destroy_ob_portal(void)
{
	t_portal	*portal;

	portal = (t_portal *) this();
	__destroy_ob();
	destroy_sprite(portal->sprits_wall[0]);
	destroy_sprite(portal->sprits_wall[1]);
	destroy_sprite(portal->sprits_wall[2]);
	destroy_sprite(portal->sprits_wall[3]);
}

void	__destroy_portal(t_portal *portal)
{
	if (portal)
	{
		destroy_sprite(portal->sprits_wall[0]);
		destroy_sprite(portal->sprits_wall[1]);
		destroy_sprite(portal->sprits_wall[2]);
		destroy_sprite(portal->sprits_wall[3]);
		portal->sprits_wall[0] = NULL;
		portal->sprits_wall[1] = NULL;
		portal->sprits_wall[2] = NULL;
		portal->sprits_wall[3] = NULL;
	}
}

static t_portal	*next_pont(t_portal *start, t_face face_dir)
{
	t_portal	*end;
	int			x;
	int			y;

	end = start;
	x = start->vector.x;
	y = start->vector.y;
	while (map()->maps_ob[y][x] && map()->maps_ob[y][x]->type == WALL)
	{
		end = (t_portal *) map()->maps_ob[y][x];
		x -= (face_dir == W);
		x += (face_dir == E);
		y -= (face_dir == S);
		y += (face_dir == N);
	}
	return (end);
}


void	__creat_portal(t_portal *portal, t_face face)
{
	t_sprite	*wall;
	t_portal	*end;

	wall = map()->sprits_wall[face];
	if (!portal->sprits_wall[face])
		portal->sprits_wall[face] = engine()->new_sprite(wall->v.w, wall->v.h);
	portal->sprite = portal->sprits_wall[face];
	(canva())->image_resize_buffer(portal->sprite, wall);
	(canva())->image_resize_buffer(portal->sprite, \
	portal->animation->list[0]);
	if (portal->action)
	{
		end = next_pont(portal, face);
		fthis()->object = (t_object *) end;
		portal->action = 0;
		if (face == W)
			__creat_portal(end, E);
		else if (face == E)
			__creat_portal(end, W);
		else if (face == S)
			__creat_portal(end, N);
		else if (face == N)
			__creat_portal(end, S);
		fthis()->object = (t_object *) portal;
	}
}
