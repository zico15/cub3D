/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/27 13:07:24 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_object_base.h>
#include <ft_nav_mesh.h>

void		__collision_enemy(t_object *collided);
void		laod_animation_enemy(t_object	*ob, int i);
int			__damage_enemy(double d);
void		attack_enemy(void);

static void	__destroy_ob_enemy(void)
{
	__destroy_ob();
	agent()->destroy();
}

static	void	__render_tester(t_buffer *b)
{
	t_player	*p;

	p = scene()->player;
	if (map()->is_print)
		b->rectangle(vector_grid_size(this()->vector, 12, 12), 0xfa0000);
	if ((!agent()->path || array(agent()->path)->size == 0) && \
	check_collision_line(this()->vector, p->vector))
		(agent())->set_destination(this()->vector, p->vector);
	/*path = agent()->path;
	if (path && array(path)->size > 0)
	{
		e = array(path)->begin;
		while (e)
		{
			pos = e->value;
			b->rectangle(vector_grid_size(*pos, 1, 1), 0xB01455);
			e = e->next;
		}
	}*/
	animation().update_all(this());
	if (this()->animation[1].is_run && this()->animation[1].index)
		attack_enemy();
}

static void	__update(void)
{
	t_vector		*v;
	void			*path;

	path = agent()->path;
	if (path)
	{
		this()->animation[0].is_run = array(path)->size > 0;
		if (array(path)->size == 0 || now() < agent()->delay)
			return ;
		if (vector_distance(scene()->player->vector, this()->vector) <= 1)
		{
			this()->animation[0].is_run = 0;
			this()->animation[1].is_run = 1;
			agent()->clear();
			return ;
		}
		v = array(path)->get(0);
		this()->set_position(*v);
		array(path)->remove_index(0);
		agent()->delay = now() + agent()->velocity;
	}
}

t_object	*new_enemy(void)
{
	t_enemy			*ob;

	ob = new_object_instance(sizeof(t_enemy));
	ob->type = ENEMY;
	ob->life = 5.0;
	ob->damage = __damage_enemy;
	ob->update = __update;
	ob->render = __render_tester;
	ob->agent = new_nav_mesh();
	ob->destroy = __destroy_ob_enemy;
	ob->collision = __collision_enemy;
	laod_animation_enemy((t_object *) ob, random_number(0, 2));
	agent()->ob = (t_object *) ob;
	(agent())->velocity = 90 + random_number(0, 80);
	return ((t_object *) ob);
}
