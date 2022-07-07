/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:17:41 by ezequeil          #+#    #+#             */
/*   Updated: 2022/07/07 21:47:11 by ezequeil         ###   ########.fr       */
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
	(nav_mesh(p->agent).set_destination)(this()->vector, \
	vector(4 * 32, 1 * 32, 0, 0));
}

void	__funct_mouse(int x, int y, int type_event)
{
	t_player	*p;

	printf("colison: %i | x: %i y: %i\n", colison().pixel(this(), x, y), x, y);
	if (type_event != 1)
		return ;
	p = (t_player *) this();
	x /= 32;
	y /= 32;
	(p->agent)->set_destination(this()->vector, \
	vector(x * 32, y * 32, 0, 0));
}

void	__set_position(t_vector v)
{
	if (colison().colison_ob(this(), v.x, v.y))
		return ;
	v.angle = this()->vector.angle;
	this()->vector = v;
}

