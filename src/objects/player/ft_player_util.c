/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:17:41 by ezequeil          #+#    #+#             */
/*   Updated: 2022/10/05 19:43:18 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_component.h>
#include <ft_player.h>

int	ft_is_collision_x(t_object *ob, double x, double y, double delta)
{
	if (colison().rectangula_ob(this(), x + delta, y))
	{
		return (1);
	}
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

void	__funct_key(int *key, int type_event)
{
	t_player	*p;
	t_vector	v;
	void		*ray_return;

	(void) type_event;
	p = (t_player *) this();
	v = p->vector;
	if (key[KEY_W])
	{
		if (!ft_is_collision_x(this(), v.x, v.y, ((double) MOVE_LEN) * engine()->delta * cos(v.angle * M_PI / 180)))
			v.x += MOVE_LEN * engine()->delta * cos(v.angle * M_PI / 180);
		if (!ft_is_collision_y(this(), v.x, v.y, -((double) MOVE_LEN) * engine()->delta * sin(v.angle * M_PI / 180)))
			v.y -= MOVE_LEN * engine()->delta * sin(v.angle * M_PI / 180);
	}
	if (key[KEY_S])
	{
		if (!ft_is_collision_x(this(), v.x, v.y, -MOVE_LEN * engine()->delta * cos(v.angle * M_PI / 180)))
			v.x -= MOVE_LEN * engine()->delta * cos(v.angle * M_PI / 180);
		if (!ft_is_collision_y(this(), v.x, v.y, MOVE_LEN * engine()->delta * sin(v.angle * M_PI / 180)))
			v.y += MOVE_LEN * engine()->delta * sin(v.angle * M_PI / 180);
	}
	if (key[KEY_A])
	{
		if (!ft_is_collision_x(this(), v.x, v.y, -((double) MOVE_LEN) * engine()->delta * sin(v.angle * M_PI / 180)))
			v.x -= MOVE_LEN * engine()->delta * sin(v.angle * M_PI / 180);
		if (!ft_is_collision_y(this(), v.x, v.y, -((double) MOVE_LEN) * engine()->delta * cos(v.angle * M_PI / 180)))
			v.y -= MOVE_LEN * engine()->delta * cos(v.angle * M_PI / 180);
	}
	if (key[KEY_D])
	{
		if (!ft_is_collision_x(this(), v.x, v.y, MOVE_LEN * engine()->delta * sin(v.angle * M_PI / 180)))
			v.x += MOVE_LEN * engine()->delta * sin(v.angle * M_PI / 180);
		if (!ft_is_collision_y(this(), v.x, v.y, MOVE_LEN * engine()->delta * cos(v.angle * M_PI / 180)))
			v.y += MOVE_LEN * engine()->delta * cos(v.angle * M_PI / 180);
	}
 	p->set_position(v);
	p->vector.angle += (((key[KEY_LEFT]) - (key[KEY_RIGHT])) * 100
			* engine()->delta);
	if (p->vector.angle > 360)
		p->vector.angle -= 360;
	if (p->vector.angle < 0)
		p->vector.angle += 360;
	if (key[65421])
		p->animation.is_run = 1;
}

void	__funct_mouse(int x, int y, int type_event)
{
	int	delta;


	delta = W_WIDTH / 2.0 - x;
	if (abs(delta) > (W_WIDTH / 5))
		this()->vector.angle += delta * ROTATION_LEN * engine()->delta;
}

void	__set_position(t_vector v)
{
	if (colison().colison_ob(this(), v.x, v.y))
		return ;
	this()->vector.x = v.x;
	this()->vector.y = v.y;
}
