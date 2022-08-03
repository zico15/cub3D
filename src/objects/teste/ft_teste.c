/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_teste.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/31 19:49:39 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_object_base.h>

static void	__funct_key(int key, int type_event)
{
	(void) key;
	(void) type_event;
	if (key != 65293)
		return ;
	printf("teste: %i\n", key);
}

static void	__colison(t_object *collided)
{
	(void) collided;
}

static void	__funct_mouse(int x, int y, int type_event)
{
	t_object	*o;
	t_vector	v;

	if (type_event == 3)
	{
		o = colison().pixel(NULL, x, y);
		printf("mouse: x: %i y: %i\n", x, y);
		if (o)
		{
			v = vector(x, y, 1, 1);
			v.radius = 1;
			printf("colison: %i | x: %i y: %i\n", \
			colison().circular(o->vector, v), x, y);
		}
	}
}

static void	__reander(t_buffer *b)
{
	//b->object(this());
}

t_object	*new_teste(void)
{
	t_object	*ob;

	ob = new_object_instance(sizeof(t_object));
	ob->funct_key = __funct_key;
	ob->render = __reander;
	ob->colison = __colison;
	ob->funct_mouse = __funct_mouse;
	return (ob);
}
