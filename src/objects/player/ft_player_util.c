/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:17:41 by ezequeil          #+#    #+#             */
/*   Updated: 2022/10/11 17:15:06 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_component.h>
#include <ft_player.h>

int	ft_is_collision_x(t_object *ob, double x, double y, double delta)
{
	if (colison().rectangula_ob(this(), x + delta, y))
		return (1);
	return (0);
}	

int	ft_is_collision_y(t_object *ob, double x, double y, double delta)
{
	if (colison().rectangula_ob(this(), x, y + delta))
	{
		return (1);
	}
	return (0);
}

// void	__funct_key(int *key, int type_event)
// {
// 	t_player	*p;
// 	t_vector	v;
// 	void		*ray_return;

// 	(void) type_event;
// 	p = (t_player *) this();
// 	v = p->vector;
// 	if (key[KEY_W])
// 	{
// 		// if (!ft_is_collision_x(this(), v.x, v.y, ((double) MOVE_LEN) * engine()->delta * cos(v.angle * M_PI / 180)))
// 			v.x += MOVE_LEN * engine()->delta * cos(v.angle * M_PI / 180);
// 		// if (!ft_is_collision_y(this(), v.x, v.y, -((double) MOVE_LEN) * engine()->delta * sin(v.angle * M_PI / 180)))
// 			v.y -= MOVE_LEN * engine()->delta * sin(v.angle * M_PI / 180);
// 	}
// 	if (key[KEY_S])
// 	{
// 		// if (!ft_is_collision_x(this(), v.x, v.y, -MOVE_LEN * engine()->delta * cos(v.angle * M_PI / 180)))
// 			v.x -= MOVE_LEN * engine()->delta * cos(v.angle * M_PI / 180);
// 		// if (!ft_is_collision_y(this(), v.x, v.y, MOVE_LEN * engine()->delta * sin(v.angle * M_PI / 180)))
// 			v.y += MOVE_LEN * engine()->delta * sin(v.angle * M_PI / 180);
// 	}
// 	if (key[KEY_A])
// 	{
// 		// if (!ft_is_collision_x(this(), v.x, v.y, -((double) MOVE_LEN) * engine()->delta * sin(v.angle * M_PI / 180)))
// 			v.x -= MOVE_LEN * engine()->delta * sin(v.angle * M_PI / 180);
// 		// if (!ft_is_collision_y(this(), v.x, v.y, -((double) MOVE_LEN) * engine()->delta * cos(v.angle * M_PI / 180)))
// 			v.y -= MOVE_LEN * engine()->delta * cos(v.angle * M_PI / 180);
// 	}
// 	if (key[KEY_D])
// 	{
// 		// if (!ft_is_collision_x(this(), v.x, v.y, MOVE_LEN * engine()->delta * sin(v.angle * M_PI / 180)))
// 			v.x += MOVE_LEN * engine()->delta * sin(v.angle * M_PI / 180);
// 		// if (!ft_is_collision_y(this(), v.x, v.y, MOVE_LEN * engine()->delta * cos(v.angle * M_PI / 180)))
// 			v.y += MOVE_LEN * engine()->delta * cos(v.angle * M_PI / 180);
// 	}
//  	p->set_position(v);
// 	p->vector.angle += (((key[KEY_LEFT]) - (key[KEY_RIGHT])) * 100
// 			* engine()->delta);
// 	if (p->vector.angle > 360)
// 		p->vector.angle -= 360;
// 	if (p->vector.angle < 0)
// 		p->vector.angle += 360;
// 	if (key[65421])
// 		p->animation.is_run = 1;
// }

void rotate(t_player *p, double angle)
{
	double oldDirX = p->dir.x;
	double oldPlaneX = p->plane.x;
		
	p->dir.x = p->dir.x * cos(angle) - p->dir.y * sin(angle);
	p->dir.y = oldDirX * sin(angle) + p->dir.y * cos(angle);
	p->plane.x = p->plane.x * cos(angle) - p->plane.y * sin(angle);
	p->plane.y = oldPlaneX * sin(angle) + p->plane.y * cos(angle);
}

void	__funct_key(int *key, int type_event)
{
	t_player *p;

	p = (t_player *) this();
	if (key[KEY_W])
	{
		if (map()->maps[(int) p->pos.y][(int)(p->pos.x + MOVE_LEN * p->dir.x)] == '0')
			p->pos.x += MOVE_LEN * p->dir.x;
		if (map()->maps[(int)(p->pos.y + MOVE_LEN * p->dir.y)][(int)p->pos.x] == '0')
			p->pos.y += MOVE_LEN * p->dir.y;
	}
	if (key[KEY_S])
	{
		if (map()->maps[(int) p->pos.y][(int)(p->pos.x - MOVE_LEN * p->dir.x)] == '0')
			p->pos.x -= MOVE_LEN * p->dir.x;
		if (map()->maps[(int)(p->pos.y - MOVE_LEN * p->dir.y)][(int)p->pos.x] == '0')
			p->pos.y -= MOVE_LEN * p->dir.y;
	}
	if (key[KEY_D])
	{
		if (map()->maps[(int) p->pos.y][(int)(p->pos.x + MOVE_LEN * p->plane.x)] == '0')
			p->pos.x += MOVE_LEN * p->plane.x;
		if (map()->maps[(int)(p->pos.y + MOVE_LEN * p->plane.y)][(int)p->pos.x] == '0')
			p->pos.y += MOVE_LEN * p->plane.y;
	}
	if (key[KEY_A])
	{
		if (map()->maps[(int) p->pos.y][(int)(p->pos.x - MOVE_LEN * p->plane.x)] == '0')
			p->pos.x -= MOVE_LEN * p->plane.x;
		if (map()->maps[(int)(p->pos.y - MOVE_LEN * p->plane.y)][(int)p->pos.x] == '0')
			p->pos.y -= MOVE_LEN * p->plane.y;
	}
	if (key[KEY_LEFT])
		rotate(p, -ROTATION_LEN);
	if (key[KEY_RIGHT])
		rotate(p, ROTATION_LEN);
}

void	__funct_mouse(int x, int y, int type_event)
{
	int		delta;
	t_player	*p;

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
