/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:56:49 by nprimo            #+#    #+#             */
/*   Updated: 2023/03/13 20:52:36 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_player.h>

void	rotate(t_player *p, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir.x;
	old_plane_x = p->plane.x;
	p->dir.x = p->dir.x * cos(angle) - p->dir.y * sin(angle);
	p->dir.y = old_dir_x * sin(angle) + p->dir.y * cos(angle);
	p->plane.x = p->plane.x * cos(angle) - p->plane.y * sin(angle);
	p->plane.y = old_plane_x * sin(angle) + p->plane.y * cos(angle);
}

void	move_dir(t_player *p, double x, double y)
{
	p->set_position(vector((p->vector.x + x * (0.00008 * engine()->world.delta_time) * \
	p->dir.x), p->vector.y, 0, 0));
	p->set_position(vector(p->vector.x, (p->vector.y + y * (0.00008 * engine()->world.delta_time) * \
	p->dir.y), 0, 0));
}

void	move_perp_dir(t_player *p, double x, double y)
{
	p->set_position(vector(p->vector.x + x * (0.00008 * engine()->world.delta_time) * \
	p->plane.x, p->vector.y, 0, 0));
	p->set_position(vector(p->vector.x, p->vector.y + y * (0.00008 * engine()->world.delta_time) * \
	p->plane.y, 0, 0));
}

void	attack_player(void)
{
	t_player	*p;
	t_object	*tmp;

	p = (t_player *) this();
	engine()->player_sound("sound/ar-epic-shot-1.ogg");
	if (!p->mira || !p->mira->damage)
		return ;
	tmp = this();
	fthis()->object = p->mira;
	p->mira->damage(1.0);
	fthis()->object = tmp;
}

int	__damage_player(double d)
{
	this()->life -= d;
	if (this()->life < 1)
		this()->life = 0;
	return (1);
}
