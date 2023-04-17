/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2023/04/17 21:08:43 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_scene_util.h>

void	__add_client(char *fd, double x, double y)
{
	t_object	*b;

	b = new_player_online(fd, x, y);
	map()->maps_ob[(int) y][(int) x] = b;
	array(scene()->free_objects)->add(b);
	(hashmap(engine()->clients))->put(fd, b);
	scene()->add(b);
}
