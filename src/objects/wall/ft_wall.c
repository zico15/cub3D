/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/07 21:50:48 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_check.h>

static void	__colison(t_object *collided)
{
	(void) collided;
	//printf("wall: %i\n", collided->type);
}

t_object	*new_wall(void)
{
	t_object		*wall;

	wall = new_object_instance(sizeof(t_object));
	wall->type = WALL;
	wall->colison = __colison;
	return (wall);
}
