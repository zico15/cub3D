/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object_base_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:13:41 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/25 14:54:06 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>

t_object	*this(void)
{
	return (fthis()->object);
}

void	*new_object_instance(size_t size)
{
	void		*o;
	t_object	*object;

	o = malloc_ob(size);
	object = (t_object *) o;
	object->update = __update_ob;
	object->destroy = __destroy_ob;
	return (o);
}
