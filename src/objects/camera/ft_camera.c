/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:20:00 by nprimo            #+#    #+#             */
/*   Updated: 2023/03/13 20:52:12 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>

void	render_view(t_player *p);
void	render_object_list(void);
void	__render_2d(t_buffer *b);

void	__render(t_buffer *b)
{
	(void) b;
	if (!scene()->player)
		return ;
	scene()->player->mira = NULL;
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

static void	__funct_key_camera(char *key, int event)
{
	t_camera	*camera;

	if (event == EVENT_CLICK && key['v'])
	{
		camera = (t_camera *) this();
		if (camera->view == VIEW_3D)
		{	
			this()->render = __render_2d;
			camera->view = VIEW_2D;
		}
		else
		{	
			this()->render = __render;
			camera->view = VIEW_3D;
		}
	}
	if (event == EVENT_CLICK && key['p'])
	{	
		if (camera->x == -1)
		{
			camera->x = scene()->player->vector.x;
			camera->y = scene()->player->vector.y;
		}
	}
}


t_object	*new_camera(void)
{
	t_camera	*camera;

	camera = new_object_instance(sizeof(t_camera));
	camera->render = __render;
	camera->view = VIEW_3D;
	camera->funct_key = __funct_key_camera;
	camera->vector = vector(0, 0, win()->w, win()->h);
	fthis()->camera = camera;
	fthis()->scene->camera = camera;
	camera->x = -1;
	camera->y = -1;
	return ((t_object *) camera);
}
