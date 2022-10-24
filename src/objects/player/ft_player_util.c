/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:17:41 by ezequeil          #+#    #+#             */
/*   Updated: 2022/10/24 19:31:03 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_player.h>

void		rotate(t_player *p, double angle);
void		move_dir(t_player *p, double x, double y);
void		move_perp_dir(t_player *p, double x, double y);
void		attack_player(void);

void	__funct_key(char *key, int event)
{
	t_player	*p;

	p = (t_player *) this();
	if (key[KEY_W])
		move_dir(p, 1, 1);
	if (key[KEY_S])
		move_dir(p, -1, -1);
	if (key[KEY_D])
		move_perp_dir(p, 1, 1);
	if (key[KEY_A])
		move_perp_dir(p, -1, -1);
	if (key[KEY_LEFT])
		rotate(p, -ROTATION_LEN);
	if (key[KEY_RIGHT])
		rotate(p, ROTATION_LEN);
	if (event == EVENT_CLICK && key[65362] && p->life < 5)
		p->life++;
	if (event == EVENT_CLICK && key[65364] && p->life > 0)
		p->life--;
}

void	__funct_mouse(int x, int y, int keycode)
{
	int			delta;
	t_player	*p;

	if (x < 0 || x > W_WIDTH)
		return ;
	(void) y;
	p = scene()->player;
	delta = W_WIDTH / 2.0 - x;
	if (abs(delta) > (W_WIDTH / 5))
		rotate(p, (double)(-delta * ROTATION_LEN / 300.0));
	if (keycode == 1 && !p->animation[0].is_run)
	{
		p->animation[0].is_run = 1;
		attack_player();
	}
}

int	__set_position(t_vector v)
{
	t_object	*ob;
	t_object	*t;

	ob = map()->maps_ob[(int) v.y][(int) v.x];
	if (ob && (ob->type == DOOR && ob->collision))
		return (0);
	if (ob)
	{
		t = this();
		if (t->collision)
			t->collision(ob);
		fthis()->object = ob;
		if (ob->collision)
			ob->collision(t);
		fthis()->object = t;
		if (ob->type != COLLECTABLE && ob->type != DOOR)
			return (0);
	}
	this()->vector.x = v.x;
	this()->vector.y = v.y;
	return (1);
}
