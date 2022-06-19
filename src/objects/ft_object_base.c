/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:13:41 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/19 15:54:49 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>

static int	__update(void)
{
	engine()->print(this());
	return (0);
}

static int	__destroy(t_object *o)
{
	printf("destroy->object\n");
	return (o != 0);
}

t_object	*new_object(void)
{
	t_object	*o;

	o = malloc_ob(sizeof(t_object));
	o->img = 0;
	o->x = 0;
	o->y = 0;
	o->update = __update;
	o->destroy = __destroy;
	return (o);
}
