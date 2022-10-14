/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 00:06:50 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/14 19:09:39 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

t_this	*fthis(void)
{
	static t_this	t;

	return (&t);
}

t_array	*array(t_array *a)
{
	fthis()->array = a;
	return (a);
}

t_engine	*engine(void)
{
	return (fthis()->engine);
}

t_buffer	*canva(void)
{
	return (fthis()->engine->canva);
}

t_scene	*scene(void)
{
	return (fthis()->scene);
}
