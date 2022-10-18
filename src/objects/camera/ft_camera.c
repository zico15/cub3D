/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:20:00 by nprimo            #+#    #+#             */
/*   Updated: 2022/10/18 17:51:34 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>

void	render_view(t_player *p);
void	render_object_list(t_camera *camera);

static void	__render(t_buffer *b)
{
	render_view(scene()->player);
	render_object_list(fthis()->camera);
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
