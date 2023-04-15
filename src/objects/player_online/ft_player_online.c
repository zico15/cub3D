/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_barrel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2023/04/15 22:45:23 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_object_base.h>

static int	__damage(double d)
{
	printf("damage: player online\n");
	return (d);
}

t_object	*new_player_online(int x, int y)
{
	t_object		*ob;

	ob = new_object_instance(sizeof(t_object));
	ob->type = OBJECT;
	ob->life = 2;
	ob->vector.x = 5;
	ob->vector.y = 5;
	map()->maps_ob[5][5] = ob;
	array(scene()->free_objects)->add(ob);
	scene()->add(ob);
	ob->damage = __damage;
	ob->collision = __collision_base;
	ob->animation = animation().create(ob, 1);
	(animation()).load_animation("imgs/barrel/frame-00.xpm", 20, \
	&(ob->animation[0]), 20);
	ob->sprite = *ob->animation->list;
	return ((t_object *) ob);
}
