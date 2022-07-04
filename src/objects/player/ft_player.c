/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:17:41 by ezequeil          #+#    #+#             */
/*   Updated: 2022/07/04 22:16:04 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_component.h>

static void	__funct_key(int key, int type_event)
{
	t_player	*p;

	(void) type_event;
	if (key != 65293)
		return ;
	p = (t_player *) this();
	fthis()->agent = p->agent;
	if (p->agent)
		(p->agent)->set_destination(p->map, this()->vector, \
		vector(4 * 32, 1 * 32, 0, 0));
}

static void	__funct_mouse(int x, int y, int type_event)
{
	t_player	*p;

	if (type_event != 1)
		return ;
	p = (t_player *) this();
	x /= 32;
	y /= 32;
	(p->agent)->set_destination(p->map, this()->vector, \
	vector(x * 32, y * 32, 0, 0));
}

static void	__update(void)
{
	t_player	*p;

	p = (t_player *) this();
	fthis()->agent = p->agent;
	render().print_ob(this());
	print_raycast(p);
	if (p->agent->rota)
	{
		if (array(p->agent->rota)->size == 0)
			return ;
		p->vector = *((t_vector *) array(p->agent->rota)->get(0));
		array(p->agent->rota)->remove_index(0);
	}
}

t_player	*new_player(void)
{
	t_player	*p;

	p = new_object_instance(sizeof(t_player));
	p->type = PLAYER;
	p->funct_key = __funct_key;
	p->update = __update;
	p->img = engine()->load_img((t_object *) p, "imgs/player.xpm");
	p->agent = new_nav_mesh();
	p->funct_mouse = __funct_mouse;
	return (p);
}
