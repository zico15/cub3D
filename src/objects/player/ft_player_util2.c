/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:56:49 by nprimo            #+#    #+#             */
/*   Updated: 2022/10/14 18:57:06 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_player.h>

void	pathte(t_player *p, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir.x;
	old_plane_x = p->plane.x;
	p->dir.x = p->dir.x * cos(angle) - p->dir.y * sin(angle);
	p->dir.y = old_dir_x * sin(angle) + p->dir.y * cos(angle);
	p->plane.x = p->plane.x * cos(angle) - p->plane.y * sin(angle);
	p->plane.y = old_plane_x * sin(angle) + p->plane.y * cos(angle);
}

void	move_dir(t_player *p, double x, double y)
{
	t_object *ob;

	ob = map()->maps_ob[(int) p->vector.y][(int)(p->vector.x + \
	x * MOVE_LEN * p->dir.x)];
	if (!ob || !ob->collision)
		p->vector.x += x * MOVE_LEN * p->dir.x;
	else if (ob)
		ob->collision((t_object *) p);
	ob = map()->maps_ob[(int)(p->vector.y + y * MOVE_LEN * \
	p->dir.y)][(int)p->vector.x];
	if (!ob || !ob->collision)
		p->vector.y += y * MOVE_LEN * p->dir.y;
	else if (ob)
		ob->collision((t_object *) p);
}

void	move_perp_dir(t_player *p, double x, double y)
{
	if (map()->maps[(int) p->vector.y][(int)(p->vector.x + x * MOVE_LEN * \
	p->plane.x)] == '0')
		p->vector.x += x * MOVE_LEN * p->plane.x;
	if (map()->maps[(int)(p->vector.y + y * MOVE_LEN * \
	p->plane.y)][(int)p->vector.x] == '0')
		p->vector.y += y * MOVE_LEN * p->plane.y;
}
