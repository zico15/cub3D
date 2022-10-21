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
void	render_object_list(void);

static void	__render(t_buffer *b)
{
	render_view(scene()->player);
	render_object_list();
}

void	swap_list(t_element *e, t_object	**obs, int index)
{
	t_object	*s;
	t_object	*temp;

	if (!e)
		return ;
	s = e->value;
	while (index < 1080 && s)
	{
		if (!obs[index])
		{
			obs[index] = s;
			break ;
		}
		else if (s->vector.distance > obs[index]->vector.distance)
		{
			temp = obs[index];
			obs[index] = s;
			s = temp;
		}
		index++;
	}
	swap_list(e->next, obs, 0);
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
