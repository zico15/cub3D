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

t_sprite	*__get_sprite_enemy(t_ray ray)
{
	t_enemy	*enemy;

	enemy = (t_enemy *) this();
	return (enemy->sprite);
}