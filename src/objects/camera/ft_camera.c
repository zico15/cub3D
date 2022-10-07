/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:20:00 by nprimo            #+#    #+#             */
/*   Updated: 2022/09/07 18:56:45 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_component.h>

void	__render(t_buffer *b)
{
	t_player	*p;

	p = scene()->player;
	if (!p)
		return ;
	render_view(p);
}

t_object	*new_camera(void)
{
	t_camera	*camera;

	camera = new_object_instance(sizeof(t_camera));
	camera->render = __render;
	camera->vector = vector(0, 0, W_WIDTH, W_HEIGHT);
	fthis()->camera = camera;
	fthis()->scene->camera = camera;
	return ((t_object *) camera);
}
