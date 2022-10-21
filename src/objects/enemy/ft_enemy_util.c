/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_teste.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/14 19:06:57 by nprimo           ###   ########.fr       */
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

void	__collision_enemy(t_object *collided)
{
	static t_player	*p;

	if (collided->type == PLAYER)
	{
		p = (t_player *) collided;
		if (p->life)
			p->life -= 1;
	}
}

void	laod_animation_enemy(t_object	*ob, int i)
{
	ob->animation = animation().create(ob, 2);
	if (i == 0)
	{
		(animation()).load_animation("imgs/enemy_a/move/frame-00.xpm", 2, \
		&ob->animation[0], 250);
		(animation()).load_animation("imgs/enemy_a/attack/frame-00.xpm", 3, \
		&ob->animation[1], 200);
	}
	else if (i == 1)
	{
		(animation()).load_animation("imgs/enemy_b/move/frame-00.xpm", 8, \
		&ob->animation[0], 150);
		(animation()).load_animation("imgs/enemy_b/attack/frame-00.xpm", 3, \
		&ob->animation[1], 200);
	}
	else if (i == 2)
	{
		(animation()).load_animation("imgs/enemy_d/move/tile00.xpm", 4, \
		&ob->animation[0], 150);
		(animation()).load_animation("imgs/enemy_d/attack/tile00.xpm", 5, \
		&ob->animation[1], 200);
	}
	ob->sprite = *ob->animation[0].list;
}

int	__damage_enemy(double d)
{
	printf("enemy life: %f\n", this()->life);
	this()->life -= d;
	if (this()->life < 0)
		this()->life = 0;
	return (1);
}

void	attack_enemy(void)
{
	t_object	*tmp;

	tmp = this();
	fthis()->object = (t_object *) scene()->player;
	printf("attack_enemy: %i\n", fthis()->object->damage(0.025));
	fthis()->object = tmp;
}
