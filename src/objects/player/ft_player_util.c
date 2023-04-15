/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:17:41 by ezequeil          #+#    #+#             */
/*   Updated: 2023/04/15 22:48:31 by edos-san         ###   ########.fr       */
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
	if (key[65505] && event == EVENT_CLICK)
	{
		if (p->mouse_move)
			mlx_mouse_show(engine()->mlx, engine()->win);
		else
			mlx_mouse_hide(engine()->mlx, engine()->win);
		p->mouse_move = !p->mouse_move;
	}
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
	if (event == EVENT_CLICK && key[KEY_SPACE])
	{	
		// t_object *b = new_barrel();
		// b->vector.x = 5;
		// b->vector.y = 5;
		// map()->maps_ob[5][5] = b;
		// printf("KEY_SPACE\n");
		// array(scene()->free_objects)->add(b);
		// scene()->add(b);
	}
	if (event == EVENT_CLICK && key[65362] && p->life < 5)
		p->life++;
	if (event == EVENT_CLICK && key[65364] && p->life > 0)
		p->life--;
}

void	__funct_mouse(int x, int y, int keycode)
{
	int			delta;
	t_player	*p;

	p = scene()->player;
	if (x < 0 || x > win()->w || y < 0 || y > win()->h)
		return ;
	delta = x - win()->w / 2;
	if (delta != x && p->mouse_move)
	{
		rotate(p, (double)(delta * 0.001));
		mlx_mouse_move(engine()->mlx, engine()->win, win()->w / 2, win()->h / 2);
	}

	//tiro-->>>
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

	ob = map()->maps_ob[(int)(v.y + v.h)][(int)(v.x + v.w)];
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
		if (ob->type != COLLECTABLE && ob->type != DOOR && ob->collision)
			return (0);
	}
	this()->vector.x = v.x;
	this()->vector.y = v.y;
	ft_send(((t_player *) this())->socket, vector_to_string(&this()->vector));
	return (1);
}
