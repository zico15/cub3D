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

t_nav_mesh *agent(void)
{
	t_enemy		*e;

	e = (t_enemy *) this();	
	fthis()->agent = e->agent;
	return (fthis()->agent);
}

void __collision_enemy(t_object *collided)
{
	static t_player	*p;

	if (collided->type == PLAYER)
	{	
		p = (t_player *) collided;
		if (p->life)
			p->life -= 1;
	}
}