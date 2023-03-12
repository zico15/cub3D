/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/12 14:29:20 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_object_base.h>

#define MINIMAP_W 206
#define MINIMAP_H 156

void	__load_animation_life(t_object *ob);

void	mini_map(t_buffer *b, t_player *p, t_vector m)
{
	t_vector	sub;

	sub = vector(p->vector.x * GRID_MIN_SIZE - 6, \
	(p->vector.y + 2) * GRID_MIN_SIZE + 4, MINIMAP_W, MINIMAP_H);
	sub.x += (MINIMAP_W / 2);
	sub.y += (MINIMAP_H / 2);
	map()->sprite->v.x = m.x;
	(map())->sprite->v.y = 0;
	(b->image_sub)(map()->sprite, sub);
	b->triangle(vector(m.x + MINIMAP_W / 2, MINIMAP_H / 2, 1, 1), \
	p->dir, p->plane, 0xd36a0d);
}

void	__render2(t_buffer *b)
{
	t_sprite	*sprite;
	int			life;

	if (scene()->player && scene()->camera->view == VIEW_3D)
	{
		if (scene()->player->sprite)
			b->image_pos(scene()->player->sprite, (win()->w / 2) - \
			(scene()->player->sprite->v.w / 2), (win()->h \
			- scene()->player->sprite->v.h));
		life = scene()->player->life;
		if (life < 1 || life > 5)
			return ;
		sprite = this()->animation[0].list[5 - life];
		b->image_pos(sprite, this()->vector.x, MINIMAP_H);
		map()->sprite->v.x = 0;
		mini_map(b, scene()->player, this()->vector);
	}
}

void	__render_map_invalido(t_buffer *b)
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
		ob->render = __render2;
	ob->vector.w = MINIMAP_W;
	ob->vector.h = MINIMAP_H;
	ob->vector.x = engine()->width - ob->vector.w;
	ob->vector.y = 0;
	ob->animation = (animation()).create(ob, 1);
	(animation()).load_animation("imgs/life/life00.xpm", 5, \
	&(ob->animation[0]), 1);
	return (ob);
}
