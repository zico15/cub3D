/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/28 20:31:55 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_object_base.h>

t_nav_mesh	*agent(void)
{
	t_enemy		*e;

	e = (t_enemy *) this();
	fthis()->agent = e->agent;
	return (fthis()->agent);
}

void	laod_animation_enemy(t_object	*ob, int i)
{
	ob->animation = animation().create(ob, 3);
	(void) i;
	(animation()).load_animation("imgs/enemy_d/move/tile00.xpm", 4, \
	&ob->animation[0], 150);
	(animation()).load_animation("imgs/enemy_d/attack/tile00.xpm", 5, \
	&ob->animation[1], 200);
	(animation()).load_animation("imgs/enemy_d/death/tile00.xpm", 4, \
	&ob->animation[2], 200);
	ob->sprite = *ob->animation[0].list;
}

int	__damage_enemy(double d)
{
	if (this()->life > -99)
		this()->life -= d;
	if (this()->life < 0 && this()->life > -99)
	{	
		this()->life = 0;
		array(scene()->updade_list)->remove_value(this());
		this()->animation[0].is_run = 0;
		this()->animation[1].is_run = 0;
		this()->animation[2].is_run = 1;
		this()->life = -100;
	}
	return (1);
}

void	attack_enemy(t_enemy *e)
{
	t_object	*tmp;

	e = (void *) e;
	tmp = this();
	fthis()->object = (t_object *) scene()->player;
	fthis()->object->damage(0.07);
	fthis()->object = tmp;
}
