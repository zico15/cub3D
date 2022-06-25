/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:01:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/25 14:19:08 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

void	__destroy_element_object(t_element	*e)
{
	t_object	*o;

	o = (t_object *) e->value;
	if (o)
		o->destroy(o);
	free_ob(e->key);
	free_ob(e->value);
	free_ob(e);
}

