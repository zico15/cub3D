/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 00:06:50 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/21 16:56:22 by edos-san         ###   ########.fr       */
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

t_scene	*scene(t_scene *scene)
{
	fthis()->scene = scene;
	return (scene);
}
