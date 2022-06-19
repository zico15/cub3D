/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/19 13:27:15 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scene_util.h>

static int	__teste(void)
{
	return (printf("object->scene\n"));
}

t_scene	*new_scene(void *file)
{
	t_scene	*scene;

	scene = malloc_ob(sizeof(t_scene));
	scene->update = __teste;
	if (0 && file)
		(array(file))->for_each(check_color, scene);
	return (scene);
}
