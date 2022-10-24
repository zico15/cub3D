/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:20:00 by nprimo            #+#    #+#             */
/*   Updated: 2022/10/24 14:19:06 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>

void	render_view(t_player *p);
void	render_object_list(void);

static void	__render(t_buffer *b)
{
	(void) b;
	if (!scene()->player)
		return ;
	render_view(scene()->player);
	scene()->player->mira = NULL;
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
