/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine_util_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/24 22:20:54 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

void	init_list_objects_functions(void)
{
	engine()->is_game = 1;
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
