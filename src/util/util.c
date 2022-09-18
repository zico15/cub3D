/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:01:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/09/18 19:05:51 by nprimo           ###   ########.fr       */
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

double	now(void)
{
	struct timeval	now;
	double 		now_msec;

	if (gettimeofday(&now, NULL) == 0)
		now_msec = now.tv_sec * 1000 + now.tv_usec / 1000;
	else
		now_msec = 0;
	return (now_msec);
}