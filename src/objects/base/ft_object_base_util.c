/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object_base_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:13:41 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/14 18:35:58 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>

t_object	*this(void)
{
	return (fthis()->object);
}

void	__collision_base(t_object *collided)
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
