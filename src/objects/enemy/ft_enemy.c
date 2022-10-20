/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/18 16:25:20 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_object_base.h>

t_nav_mesh	*agent(void);
void 		__collision_enemy(t_object *collided);
void 		laod_animation_enemy(t_object	*ob);

static int	check_line(t_vector begin, t_vector end)
{
	int			pixels;
	t_vector	delta;
	t_object	*ob;

	delta.x = end.x - begin.x;
	delta.y = end.y - begin.y;
	pixels = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	delta.x /= pixels;
	delta.y /= pixels;
	delta.w = begin.x;
	delta.h = begin.y;
	while (pixels-- > 0)
	{
		ob = map()->maps_ob[(int) delta.h][(int) delta.w];
		if (ob && ob != this() && ob->type != PLAYER && ob->collision)
			return (0);
		delta.w  += delta.x;
		delta.h += delta.y;
	}
	return (1);
}

static void	__render_tester(t_buffer *b)
{
	t_player	*p;
	t_vector	v;
	void		*path;
	t_element	*e;
	t_vector	*pos;

	p = scene()->player;
	v = vector_grid(this()->vector);
	if (map()->is_print)
		b->rectangle(vector_grid_size(this()->vector, 12, 12), 0xfa0000);
	if ((!agent()->path || array(agent()->path)->size == 0) && check_line(this()->vector, p->vector))
		agent()->set_destination(this()->vector, p->vector);
	path = agent()->path;
	if (path && array(path)->size > 0)
	{
		e = array(path)->begin;
		while (e)
		{
			pos = e->value;
			b->rectangle(vector_grid_size(*pos, 1, 1), 0xB01455);
			e = e->next;
		}	
	}
	animation().update_all(this());
}

static void	__update(void)
{
	t_vector		*v;
	void			*path;

	path = agent()->path;
	if (path)
	{
		this()->animation[0].is_run = array(path)->size > 0;
		if (array(path)->size == 0 ||  now() < agent()->delay)
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

static void funct_key(int *key, int event)
{
	
	if (event != EVENT_CLICK)
		return;
	agent()->set_destination(this()->vector, scene()->player->vector);
}

t_object	*new_enemy(void)
{
	t_enemy			*ob;

	ob = new_object_instance(sizeof(t_enemy));
	ob->type = ENEMY;
	ob->update = __update;
	ob->render = __render_tester;
	ob->funct_key = funct_key;
	ob->agent = new_nav_mesh();
	ob->collision = __collision_enemy;
	laod_animation_enemy((t_object *) ob);
	agent()->ob = (t_object *) ob;
	agent()->velocity = 90 + random_number(0, 80);
	return ((t_object *) ob);
}
