/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 03:01:53 by edos-san          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/19 12:01:14 by edos-san         ###   ########.fr       */
=======
/*   Updated: 2022/06/19 03:14:27 by edos-san         ###   ########.fr       */
>>>>>>> ezequiel
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

void	check_color(t_element *e, void *o)
{
	t_scene	*scene;

	scene = o;
	if (string().equals_n(e->value, "F ", 2))
	{
		if (scene->f)
			engine()->close("Error");
		scene->f = e->value;
		printf("F: %s", scene->f);
	}
	if (string().equals_n(e->value, "C ", 2))
	{
		if (scene->c)
			engine()->close("Error");
		scene->c = e->value;
		printf("C: %s", scene->c);
	}
}
