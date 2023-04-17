/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_online.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2023/04/17 22:48:05 by edos-san         ###   ########.fr       */
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

static int	__set_position(t_vector v)
{
	t_vector	temp;

	printf("__set_position\n");
	temp = this()->vector;
	if (map()->maps_ob[(int) v.y][(int) v.x])
		return (0);
	map()->maps_ob[(int) temp.y][(int) temp.x] = NULL;
	map()->maps_ob[(int) v.y][(int) v.x] = this();
	this()->vector.x = v.x;
	this()->vector.y = v.y;
	return (1);
}

t_object	*new_player_online(char *fd, double x, double y)
{
	t_player		*ob;

	ob = new_object_instance(sizeof(t_player));
	ob->type = ENEMY;
	ob->fd = fd;
	ob->life = 5;
	ob->vector.x = x;
	ob->vector.y = y;
	ob->set_position = __set_position;
	ob->damage = __damage;
	ob->collision = __collision_base;
	ob->animation = animation().create(ob, 1);
	(animation()).load_animation("imgs/enemy_d/move/tile00.xpm", 4, \
	&(ob->animation[0]), 20);
	ob->sprite = *ob->animation->list;
	return ((t_object *) ob);
}
