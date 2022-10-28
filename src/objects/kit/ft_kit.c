/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/28 17:34:57 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_object_base.h>

static void	__render(t_buffer *b)
{
	if (map()->is_print)
		b->rectangle(vector_grid_size(this()->vector, 12, 12), 0x7fff00);
}

static void	__collision_ki(t_object *collided)
{
	t_player	*p;

	if (collided->type == PLAYER)
	{
		p = (t_player *) collided;
		if (p->life < 5)
		{
			p->life++;
			scene()->remove_object(this());
		}
	}	
}

t_object	*new_kit(void)
{
	t_object		*ob;

	ob = new_object_instance(sizeof(t_object));
	ob->type = COLLECTABLE;
	ob->render = __render;
	ob->collision = __collision_ki;
	ob->sprite = engine()->load_sprite("imgs/kit/frame-00.xpm");
	return ((t_object *) ob);
}
