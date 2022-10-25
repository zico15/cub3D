/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/25 20:48:45 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_object_base.h>

void	__load_animation_life(t_object *ob);

void	mini_map2(t_buffer *b, t_vector p, t_vector m)
{
	(void) b;
	(void) p;
	(void) m;
	/*t_vector	v;
	t_vector	p_rel;
	t_vector	direction;
	t_player	*player;
	//double		val;

	player = scene()->player;
	v = vector(p.x * GRID_MIN_SIZE, p.y * GRID_MIN_SIZE, 200, 150);
	//b->rectangle_border(m, 0xe5e6e6, 3, 0xdf0707);
	m.x += 3;
	m.y += 3;
	m.w -= 6;
	m.h -= 6;
	//map()->sprite->v = m;
	p_rel.x = m.x + 91 - 2 * GRID_MIN_SIZE;
	p_rel.y = m.y + 72 - GRID_MIN_SIZE;
	direction.x = p_rel.x + p.w / 2 + player->dir.x * 10;
	direction.y = p_rel.y + p.h / 2 + player->dir.y * 10;*/
	/*b->image_sub(map()->sprite, v);
	b->rectangle(vector(p_rel.x - p.w / 2, p_rel.y - p.h / 2, \
	p.w, p.h), 0xd36a0d);
	b->rectangle(vector(direction.x, direction.y, 2, 2),
		0x00990099);*/
}

void	mini_map(t_buffer *b, t_vector p, t_vector m)
{
	t_vector	sub;
	t_vector	p_rel;
	t_vector	direction;

	sub = vector(p.x * GRID_MIN_SIZE, p.y * GRID_MIN_SIZE, 206, 156);
	sub.x += 103;
	sub.y += 78;
	(void) m;
	map()->sprite->v.x = m.x;
	(map())->sprite->v.y = 2.0;
	(b->image_sub)(map()->sprite, sub);
	p_rel.x = m.x + 91 - 2 * GRID_MIN_SIZE;
	p_rel.y = m.y + 72 - GRID_MIN_SIZE;
	direction.x = p_rel.x + p.w / 2 + scene()->player->dir.x * 10;
	direction.y = p_rel.y + p.h / 2 + scene()->player->dir.y * 10;
	b->rectangle(vector(p_rel.x - p.w / 2, p_rel.y - p.h / 2, \
	5, 5), 0xd36a0d);
	b->rectangle(vector(direction.x, direction.y, 2, 2),
		0x00990099);
}

static void	__render(t_buffer *b)
{
	t_sprite	*sprite;
	int			life;

	if (scene()->player)
	{
		if (scene()->player->sprite)
			b->image_pos(scene()->player->sprite, 0, 100);
		life = scene()->player->life;
		if (life < 1 || life > 5)
			return ;
		//printf("life: %i\n", life);
		sprite = this()->animation[0].list[5 - life];
		b->image_pos(sprite, this()->vector.x, 156);
		mini_map(b, scene()->player->vector, this()->vector);
	}
	/*p = scene()->player->vector;
	(void) p;
	//mini_map(b, p, this()->vector);
	if (0 && scene()->player->sprite)
		b->image_pos(scene()->player->sprite, 0, 100);
	if (!scene()->player->life)
		return ;*/
}

static	void	__render_map_invalido(t_buffer *b)
{
	static t_sprite	*sprite;

	if (!sprite)
		sprite = engine()->load_sprite("imgs/background.xpm");
	else
		b->image_resize(sprite, win()->w, win()->h);
}

t_object	*new_menu(void)
{
	t_object	*ob;

	ob = new_object_instance(sizeof(t_object));
	ob->render = __render_map_invalido;
	if (fthis()->player)
		ob->render = __render;
	ob->vector.w = 206;
	ob->vector.h = 156;
	ob->vector.x = engine()->width - ob->vector.w;
	ob->vector.y = 0;
	ob->animation = (animation()).create(ob, 1);
	(animation()).load_animation("imgs/life/life00.xpm", 5, \
	&(ob->animation[0]), 1);
	return (ob);
}
