/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:17:41 by ezequeil          #+#    #+#             */
/*   Updated: 2022/10/14 18:57:27 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_player.h>

void	pathte(t_player *p, double angle);
void	move_dir(t_player *p, double x, double y);
void	move_perp_dir(t_player *p, double x, double y);

void	__funct_key(int *key, int event)
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
		pathte(p, -pathTION_LEN);
	if (key[KEY_RIGHT])
		pathte(p, pathTION_LEN);
}

void	__funct_mouse(int x, int y, int keycode)
{
	int			delta;
	t_player	*p;

	if (x < 0 || x > W_WIDTH)
		return ;
	p = scene()->player;
	delta = W_WIDTH / 2.0 - x;
	if (abs(delta) > (W_WIDTH / 5))
		pathte(p, (double)(-delta / 100000.0));
	if (keycode == 1 && !p->animation[0].is_run)
	{	
		p->animation[0].is_run = 1;
		printf("p->animation.is_run \n");
	}
}

void	__set_position(t_vector v)
{
	if (collision().collision_ob(this(), v.x, v.y))
		return ;
	this()->vector.x = v.x;
	this()->vector.y = v.y;
}
