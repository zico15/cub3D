/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:56:49 by nprimo            #+#    #+#             */
/*   Updated: 2022/10/18 10:24:39 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_player.h>

void	rotate(t_player *p, double angle)
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
	p->set_position(vector(p->vector.x + x * MOVE_LEN * \
	p->dir.x, p->vector.y, 1, 1));
	p->set_position(vector(p->vector.x,  (p->vector.y + y * MOVE_LEN * \
	p->dir.y), 1, 1));
}

void	move_perp_dir(t_player *p, double x, double y)
{
	p->set_position(vector(p->vector.x + x * MOVE_LEN * \
	p->plane.x, p->vector.y, 1, 1));
	p->set_position(vector(p->vector.x, p->vector.y + y * MOVE_LEN * \
	p->plane.y, 1, 1));	
}
