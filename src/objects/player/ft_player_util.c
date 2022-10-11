/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:17:41 by ezequeil          #+#    #+#             */
/*   Updated: 2022/10/11 18:11:24 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_component.h>
#include <ft_player.h>

void	rotate(t_player *p, double angle)
{
	double oldDirX = p->dir.x;
	double oldPlaneX = p->plane.x;
		
	p->dir.x = p->dir.x * cos(angle) - p->dir.y * sin(angle);
	p->dir.y = oldDirX * sin(angle) + p->dir.y * cos(angle);
	p->plane.x = p->plane.x * cos(angle) - p->plane.y * sin(angle);
	p->plane.y = oldPlaneX * sin(angle) + p->plane.y * cos(angle);
}

void	move_dir(t_player *p, double x, double y)
{
	if (
		map()->maps[(int) p->pos.y][(int)(p->pos.x + x * MOVE_LEN * p->dir.x)] == '0')
		p->pos.x += x * MOVE_LEN * p->dir.x;
	if (map()->maps[(int)(p->pos.y + y * MOVE_LEN * p->dir.y)][(int)p->pos.x] == '0')
		p->pos.y += y * MOVE_LEN * p->dir.y;
}

void	move_perp_dir(t_player *p, double x, double y)
{
	if (map()->maps[(int) p->pos.y][(int)(p->pos.x + x * MOVE_LEN * p->plane.x)] == '0')
		p->pos.x += x * MOVE_LEN * p->plane.x;
	if (map()->maps[(int)(p->pos.y + y * MOVE_LEN * p->plane.y)][(int)p->pos.x] == '0')
		p->pos.y += y * MOVE_LEN * p->plane.y;
}

void	__funct_key(int *key, int type_event)
{
	t_player *p;

	p = (t_player *) this();
	if (key[KEY_W])
		move_dir(p, 1, 1);
	if (key[KEY_S])
		move_dir(p, -1, -1);
	if (key[KEY_D])
		move_perp_dir(p, 1, 1);
	if (key[KEY_A])
		move_perp_dir(p, -1, -1);
	if (key[KEY_LEFT])
		rotate(p, -ROTATION_LEN);
	if (key[KEY_RIGHT])
		rotate(p, ROTATION_LEN);
}

void	__funct_mouse(int x, int y, int type_event)
{
	int		delta;
	t_player	*p;

	if (x < 0 || x > W_WIDTH)
		return ;
	p = scene()->player;
	delta = W_WIDTH / 2.0 - x;
	if (abs(delta) > (W_WIDTH / 5))
		rotate(p, (double) (-delta / 100000.0));
}

void	__set_position(t_vector v)
{
	if (colison().colison_ob(this(), v.x, v.y))
		return ;
	this()->vector.x = v.x;
	this()->vector.y = v.y;
}
