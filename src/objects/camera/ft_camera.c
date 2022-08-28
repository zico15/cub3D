/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:20:00 by nprimo            #+#    #+#             */
/*   Updated: 2022/08/28 18:25:54 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_component.h>

#define GREEN 0x0000FF00

static void	__render_column(t_buffer *b, t_object *p, \
t_vector obj, int ray_count)
{
	t_vector	column;
	double		render_scale;
	double		distance;
	double		distance_hor;

	distance = get_vectors_distance(p->vector, obj);
	distance_hor = distance * ft_cos(obj.angle);
	column.h = (int) W_HEIGHT / distance_hor;
	if (column.h >= W_HEIGHT)
		column.h = W_HEIGHT;
	column.w = W_WIDTH / N_RAYS;
	column.x = (ray_count * column.w);
	column.y = W_HEIGHT / 2 - column.h / 2;
	if (column.y < 0)
		column.y = 0;
	if (column.x < 0)
		column.x = 0;
	b->rectangle(column, GREEN);
}

static void	__render_view(t_element *e, void *o)
{
	t_vector	*obj;
	t_object	*p;

	p = (t_object *) o;
	obj = (t_vector *) e->value;
	__render_column(canva(), p, *obj, e->index);
}

void	__render(t_buffer *b)
{
	t_player	*p;
	void		*ray_return;

	p = scene()->player;
	if (!p)
		return ;
	canva()->rectangle(vector(0, 0, W_WIDTH, W_HEIGHT), 0xc4994a);
	// p->animation.is_run = 1;
	ray_return = print_raycast(p);
	array(ray_return)->for_each(fthis()->camera->render_view, p);
	array(ray_return)->destroy();
}

t_object	*new_camera(void)
{
	t_camera	*camera;

	camera = new_object_instance(sizeof(t_camera));
	// camera->render_view = __render_view;
	// camera->render = __render;
	camera->vector = vector(0, 0, W_WIDTH, W_HEIGHT);
	fthis()->camera = camera;
	fthis()->scene->camera = camera;
	return ((t_object *) camera);
}

