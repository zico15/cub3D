/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine_util_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/26 18:15:21 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

void	init_list_objects_functions(void)
{
	int		w;
	int		h;

	mlx_get_screen_size(engine()->mlx, &w, \
	&h);
	engine()->v.w = 1080;
	engine()->v.h = 800;
	engine()->width = engine()->v.w;
	engine()->height = engine()->v.h;
	engine()->is_game = 0;
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
