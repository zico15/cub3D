/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:17:41 by ezequeil          #+#    #+#             */
/*   Updated: 2022/07/09 20:12:08 by ezequeil         ###   ########.fr       */
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

	(void) type_event;
	p = (t_player *) this();
	v = p->vector;
	v.x += (((key == KEY_D) - (key == KEY_A)) * 5);
	v.y += (((key == KEY_S) - (key == KEY_W)) * 5);
	p->set_position(v);
	p->vector.angle += (((key == KEY_RIGHT) - (key == KEY_LEFT)) * 5);
	if (key != 65293)
		return ;
}

void	__funct_mouse(int x, int y, int type_event)
{
	t_player	*p;
	t_object	*o;
	t_vector	v;

	if (type_event == 3)
	{
		o = colison().colison_ob(this(), x, y);
		printf("colison--> %i\n", o != NULL);
		if (o)
		{
			v = vector(x, y, 1, 1);
			v.radius = 1;
			printf("colison: %i | x: %i y: %i\n", \
			colison().circular(o->vector, v), x, y);
		}
	}
	if (type_event != 1)
		return ;
	p = (t_player *) this();
	x /= GRID_SIZE;
	y /= GRID_SIZE;
	(p->agent)->set_destination(this()->vector, \
	vector(x * GRID_SIZE, y * GRID_SIZE, 0, 0));
}

void	__set_position(t_vector v)
{
	if (colison().colison_ob(this(), v.x, v.y))
		return ;
	v.angle = this()->vector.angle;
	this()->vector = v;
}
