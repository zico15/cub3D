/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 00:06:50 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/31 21:06:51 by edos-san         ###   ########.fr       */
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

