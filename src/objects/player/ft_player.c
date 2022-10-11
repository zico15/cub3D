/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:17:41 by ezequeil          #+#    #+#             */
/*   Updated: 2022/10/11 18:03:48 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_component.h>
#include <ft_player.h>

void	raycast(t_player *p, double rel_angle);

// static void	__reander(t_buffer *b)
// {
// 	t_player	*p;
// 	t_vector	v;
// 	t_vector	dir;

// 	p = (t_player *) this();
// 	fthis()->agent = p->agent;
// 	b->rectangle(vector(p->vector.x - p->vector.w / 2, p->vector.y - p->vector.h / 2, p->vector.w, p->vector.h), 0xf2ad0d);
// 	dir.x = (int) p->vector.x + ft_cos(p->vector.angle) * 20;
// 	dir.y = (int) p->vector.y - ft_sin(p->vector.angle) * 20;
// 	b->rectangle(vector(dir.x - 1, dir.y - 1, 2, 2), 0xdf0707);
// }

static void	__update(void)
{
	t_player		*p;
	t_vector		v;
	static int		count;

	p = fthis()->player;
	fthis()->agent = p->agent;
	if (p->agent->rota)
	{
		if (array(p->agent->rota)->size == 0)
			return ;
		p->set_position(*((t_vector *) array(p->agent->rota)->get(0)));
		array(p->agent->rota)->remove_index(0);
	}
	if (++count < 5000)
		count = 0;
	if (p->animation.is_run)
		set_animation((t_object *) p, 0);
}

static void	__colison(t_object *collided)
{
	if (!collided)
		printf("collided: %i\n", collided->type);
}

t_player	*new_player(void)
{
	t_player	*p;

	p = new_object_instance(sizeof(t_player));
	p->type = PLAYER;
	p->funct_key = __funct_key;
	p->update = __update;
	// p->render = __reander;
	p->agent = new_nav_mesh();
	p->sprite = engine()->load_sprite("imgs/IMG/Arma01.xpm");
	p->funct_mouse = __funct_mouse;
	p->colison = __colison;
	p->vector.angle = 90;
	p->vector.w = 10;
	p->vector.h = 10;
	p->set_position = __set_position;
	__load_animation(p);
	fthis()->player = p;
	return (p);
}
