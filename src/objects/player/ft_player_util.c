/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:17:41 by ezequeil          #+#    #+#             */
/*   Updated: 2022/08/22 21:03:31 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_component.h>
#include <ft_player.h>

void printf_element(t_element *e, void *o)
{
	t_vector *v;
	t_player *p;

	p = o;
	v = (t_vector *) e->value;
	printf("x: %f y: %f d> %f\n", v->x, v->y, get_vectors_distance(*v , p->vector));
}

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
		v.x += MOVE_LEN * sin(v.angle * M_PI / 180); 
		v.y -= MOVE_LEN * cos(v.angle * M_PI / 180);
	}
	if (key == KEY_S)
	{
		v.x -= MOVE_LEN * sin(v.angle * M_PI / 180); 
		v.y += MOVE_LEN * cos(v.angle * M_PI / 180);
	}
	if (key == KEY_A)
	{
		v.x -= MOVE_LEN * cos(v.angle * M_PI / 180); 
		v.y -= MOVE_LEN * sin(v.angle * M_PI / 180);
	}
	if (key == KEY_D)
	{
		v.x += MOVE_LEN * cos(v.angle * M_PI / 180); 
		v.y += MOVE_LEN * sin(v.angle * M_PI / 180);
	}
	if (key == 32)
	{
		canva()->rectangle(vector(0, 0, W_WIDTH, W_HEIGHT), 0xc4994a);
		p->animation.is_run = 1;
		ray_return = print_raycast(p);
		// array(ray_return)->for_each(printf_element, p);
		array(ray_return)->for_each(fthis()->camera->render_view, p);
		array(ray_return)->destroy();

	}
 	p->set_position(v);
	p->vector.angle += (((key == KEY_RIGHT) - (key == KEY_LEFT)) * 5);
	if (p->vector.angle > 360)
		p->vector.angle -= 360;
	if (p->vector.angle < 0)
		p->vector.angle += 360;
}

void	__funct_mouse(int x, int y, int type_event)
{
	t_player	*p;
	t_object	*o;
	t_vector	v;

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
	this()->vector.x = v.x;
	this()->vector.y = v.y;
}
