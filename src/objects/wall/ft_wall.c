/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/01 14:13:46 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_check.h>

static void	__colison(t_object *collided)
{
	(void) collided;
	printf("wall: %i\n", collided->type);
}

static void	__reander(t_buffer *b)
{
	b->rectangle(this()->vector, 0x0000FF00);
	
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
