/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object_base_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:13:41 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/04 18:27:57 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>

t_object	*this(void)
{
	return (fthis()->object);
}

void	__colison_base(t_object *collided)
{
	(void) collided;
}

void	*new_object_instance(size_t size)
{
	void		*o;
	t_object	*object;

	o = malloc_ob(size);
	object = (t_object *) o;
	object->destroy = __destroy_ob;
	object->funct_key = NULL;
	object->type = OBJECT;
	fthis()->object = o;
	return (o);
}
