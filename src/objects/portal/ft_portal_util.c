/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_portal_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/08 18:38:51 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_check.h>

void	__creat_portal(t_portal *portal, t_face face);

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
		if (portal->next)
		{
			portal->next->next = NULL;
			__destroy_portal(portal->next);
		}
		portal->next = NULL;
	}
}

static t_vector	get_next_position(t_portal *portal, t_face face_dir)
{
	double			x;
	double			y;

	x = portal->vector.x;
	y = portal->vector.y;
	x += (face_dir == W) * 1;
	x -= (face_dir == E) * 1;
	y += (face_dir == S) * 1;
	y -= (face_dir == N) * 1;
	if (face_dir != W && face_dir != E)
		y = (int) y;
	else if (face_dir != S && face_dir != N)
		x = (int) x;
	return (vector(x, y, 0, 0));
}

static t_portal	*next_pont(t_portal *start, t_face face_dir)
{
	t_portal	*end;
	int			x;
	int			y;

	end = NULL;
	x = start->vector.x;
	y = start->vector.y;
	if (x <= 0 || y <= 0 || x >= map()->grid_width || y >= map()->grid_height)
		return (NULL);
	while (map()->maps_ob[y][x] && map()->maps_ob[y][x]->type == WALL)
	{
		printf("x: %i y: %i w: %i h: %i\n", x, y, map()->grid_width, map()->grid_height);
		end = (t_portal *) map()->maps_ob[y][x];
		x -= (face_dir == W);
		x += (face_dir == E);
		y -= (face_dir == S);
		y += (face_dir == N);
		printf("x: %i y: %i w: %i h: %i\n", x, y, map()->grid_width, map()->grid_height);
		if (x <= 0 || y <= 0 || x >= map()->grid_width || y >= map()->grid_height)
		{
			printf("Not\n");
			return (NULL);
		}
	}
	printf("fx: %i fy: %i fw: %i fh: %i\n", x, y, map()->grid_width, map()->grid_height);
	return (end);
}


void	creat_portal_end(t_portal *portal, t_face face)
{
	t_portal	*end;

	end = next_pont(portal, face);
	portal->next = end;
	portal->action = 0;
	if (end == NULL)
		return ;
	end->next = portal;
	fthis()->object = (t_object *) end;
	if (face == W)
		__creat_portal(end, E);
	else if (face == E)
		__creat_portal(end, W);
	else if (face == S)
		__creat_portal(end, N);
	else if (face == N)
		__creat_portal(end, S);
}

void	__creat_portal(t_portal *portal, t_face face)
{
	t_sprite	*wall;
	t_vector	temp;

	portal->face = face;
	portal->animation->time = now();
	wall = map()->sprits_wall[face];
	if (!portal->sprits_wall[face])
		portal->sprits_wall[face] = engine()->new_sprite(wall->v.w, wall->v.h);
	portal->sprite = portal->sprits_wall[face];
	(canva())->image_resize_buffer(portal->sprite, wall);
	(canva())->image_resize_buffer(portal->sprite, \
	portal->animation->list[0]);
	portal->next_position = get_next_position(portal, face);
	if (portal->action)
	{
		creat_portal_end(portal, face);
		fthis()->object = (t_object *) portal;
	}
	else if (portal->next)
	{
		temp = portal->next_position;
		portal->next_position = portal->next->next_position;
		portal->next->next_position = temp;
	}
}
