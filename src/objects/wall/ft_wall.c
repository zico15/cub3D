/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/11 17:39:11 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_check.h>

void	__colison(t_object *collided)
{
	(void) collided;
	printf("wall: %i\n", collided->type);
}

static void	__reander(void)
{
	render().print_ob(this());
}

t_object	*new_wall(void)
{
	t_object		*wall;
	static void		*img;

	wall = new_object_instance(sizeof(t_object));
	wall->type = WALL;
	if (!img)
		img = engine()->load_img(NULL, "imgs/wall.xpm");
	wall->img = img;
	wall->colison = __colison;
	wall->render = __reander;
	return (wall);
}
