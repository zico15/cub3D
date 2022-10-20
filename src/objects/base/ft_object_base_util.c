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

static int	__set_position(t_vector v)
{
	t_vector	temp;
	t_object	*ob;

	temp = this()->vector;
	ob	= map()->maps_ob[(int) v.y][(int) v.x];
	if (ob && ob->type != DOOR)
		return (0);
	if (ob)
	{
		map()->maps_ob[(int) temp.y][(int) temp.x] = NULL;
		map()->maps_ob[(int) v.y][(int) v.x] = this();
	}
	this()->vector.x = v.x;
	this()->vector.y = v.y;
	return (1);
}

static t_sprite	*__get_sprite_base(t_ray ray)
{
	return (this()->sprite);
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
	object->get_sprite = __get_sprite_base;
	object->set_position = __set_position;
	fthis()->object = o;
	return (o);
}
