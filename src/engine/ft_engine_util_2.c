/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/18 14:52:18 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

void	init_list_objects_functions(void)
{
	engine()->new_obs['1'] = new_wall;
	engine()->new_obs['I'] = new_enemy;
	engine()->new_obs['K'] = new_kit;
	engine()->new_obs['D'] = new_door;
	engine()->new_obs['N'] = new_player;
	engine()->new_obs['S'] = new_player;
	engine()->new_obs['W'] = new_player;
	engine()->new_obs['E'] = new_player;
	engine()->new_obs['T'] = new_barrel;
}
