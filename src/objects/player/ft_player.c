/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:17:41 by ezequeil          #+#    #+#             */
/*   Updated: 2022/07/09 20:07:02 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_component.h>
#include <ft_player.h>

static void	__reander(void)
{
	t_player	*p;
	t_vector	v;

	p = (t_player *) this();
	fthis()->agent = p->agent;
	render().print_ob(this());
	print_raycast(p);
}

static void	__update(void)
{
	t_player	*p;
	t_vector	v;

	p = (t_player *) this();
	fthis()->agent = p->agent;
	if (p->agent->rota)
	{
		if (array(p->agent->rota)->size == 0)
			return ;
		p->set_position(*((t_vector *) array(p->agent->rota)->get(0)));
		array(p->agent->rota)->remove_index(0);
	}
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
	p->img = engine()->load_img(NULL, "imgs/player.xpm");
	p->agent = new_nav_mesh();
	p->funct_mouse = __funct_mouse;
	p->colison = __colison;
	p->vector.angle = 90;
	p->set_position = __set_position;
	return (p);
}
