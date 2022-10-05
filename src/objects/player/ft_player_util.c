/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:17:41 by ezequeil          #+#    #+#             */
/*   Updated: 2022/09/18 19:08:25 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_component.h>
#include <ft_player.h>

void	__funct_key(int key, int type_event)
{
	t_player	*p;
	t_vector	v;
	void		*ray_return;

	(void) type_event;
	p = (t_player *) this();
	v = p->vector;
	if (key == KEY_W)
	{
		v.x += MOVE_LEN * engine()->delta * cos(v.angle * M_PI / 180); 
		v.y -= MOVE_LEN * engine()->delta * sin(v.angle * M_PI / 180);
	}
	if (key == KEY_S)
	{
		v.x -= MOVE_LEN * engine()->delta * cos(v.angle * M_PI / 180); 
		v.y += MOVE_LEN * engine()->delta * sin(v.angle * M_PI / 180);
	}
	if (key == KEY_A)
	{
		v.x -= MOVE_LEN * engine()->delta * sin(v.angle * M_PI / 180); 
		v.y -= MOVE_LEN * engine()->delta * cos(v.angle * M_PI / 180);
	}
	if (key == KEY_D)
	{
		v.x += MOVE_LEN * engine()->delta * sin(v.angle * M_PI / 180); 
		v.y += MOVE_LEN * engine()->delta * cos(v.angle * M_PI / 180);
	}
 	p->set_position(v);
	p->vector.angle += (((key == KEY_LEFT) - (key == KEY_RIGHT)) * 100
			* engine()->delta);
	if (p->vector.angle > 360)
		p->vector.angle -= 360;
	if (p->vector.angle < 0)
		p->vector.angle += 360;
	if (key == 65421)
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
