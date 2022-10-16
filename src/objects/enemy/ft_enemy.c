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

t_nav_mesh	*agent(void);
t_sprite	*__get_sprite_enemy(t_ray ray);
void 		__collision_enemy(t_object *collided);

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

	p = scene()->player;
	v = vector_grid(this()->vector);
	if (map()->is_print)
		b->rectangle(vector_grid_size(this()->vector, 2, 2), 0xfa0000);
	if ((!agent()->path || array(agent()->path)->size == 0) && check_line(this()->vector, p->vector))
		agent()->set_destination(this()->vector, p->vector);
}

static void	__update(void)
{
	t_vector		*v;
	static int		count;
	void			*path;

	path = agent()->path;
	if (path)
	{
		if (array(path)->size == 0 || count++ < 100)
			return ;
		if (vector_distance(scene()->player->vector, this()->vector) <= 1)
		{
			agent()->clear();
			return ;
		}
		count = 0;
		v = array(path)->get(0);
		this()->set_position(*v);
		printf("vx: %f vy: %f\n", v->x, v->y);
		array(path)->remove_index(0);
	}
}

t_object	*new_enemy(void)
{
	t_enemy			*ob;
	static t_sprite	*sprite;

	ob = new_object_instance(sizeof(t_enemy));
	if (sprite == NULL)
		sprite = engine()->load_sprite("imgs/enemy.xpm");
	ob->type = ENEMY;
	ob->sprite = sprite;
	ob->update = __update;
	ob->render = __render_tester;
	ob->agent = new_nav_mesh();
	ob->collision = __collision_enemy;
	ob->get_sprite = __get_sprite_enemy;
	agent()->ob = (t_object *) ob;
	return ((t_object *) ob);
}
