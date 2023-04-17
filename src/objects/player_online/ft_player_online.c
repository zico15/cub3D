/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_online.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2023/04/17 19:59:11 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_object_base.h>

static int	__damage(double d)
{
	t_player	*p;

	p = (t_player *) this();
	printf("damage-> player online: %s\n", p->fd);
	return (d);
}

t_object	*new_player_online(char *fd, double x, double y)
{
	t_player		*ob;

	ob = new_object_instance(sizeof(t_player));
	ob->type = OBJECT;
	ob->fd = fd;
	ob->life = 5;
	ob->vector.x = x;
	ob->vector.y = y;
	ob->damage = __damage;
	ob->collision = __collision_base;
	ob->animation = animation().create(ob, 1);
	(animation()).load_animation("imgs/barrel/frame-00.xpm", 20, \
	&(ob->animation[0]), 20);
	ob->sprite = *ob->animation->list;
	return ((t_object *) ob);
}
