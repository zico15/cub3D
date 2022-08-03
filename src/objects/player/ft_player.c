/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:17:41 by ezequeil          #+#    #+#             */
/*   Updated: 2022/08/03 21:59:00 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_component.h>
#include <ft_player.h>

static void	__reander(t_buffer *b)
{
	t_player	*p;
	t_vector	v;
	void		*list;

	p = (t_player *) this();
	fthis()->agent = p->agent;
	b->rectangle(this()->vector, 0xf2ad0d);
	list = print_raycast(p);
	if (list)
		array(list)->destroy();
}

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
	p->render = __reander;
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
