/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:20:00 by nprimo            #+#    #+#             */
/*   Updated: 2022/08/27 12:13:30 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>

#define GREEN 0x0000FF00

static void	__render_column(t_buffer *b, t_object *p, \
t_vector obj, int ray_count)
{
	t_vector	column;
	double		render_scale;
	double		distance;
	double		distance_hor;

	distance = get_vectors_distance(p->vector, obj);
	distance_hor = distance * cos(obj.angle * PI / 180);
	// render_scale = distance / GRID_SIZE;
	// if (render_scale < 0)
	// 	render_scale = 1;
	// printf("render scale %f\n", render_scale);
	column.h = W_HEIGHT / distance_hor;
	column.w = W_WIDTH / VIEW_ANGLE;
	column.x = (ray_count * column.w);
	column.y = W_HEIGHT / 2 + column.h / 2;
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

t_object	*new_camera(void)
{
	t_camera	*camera;

	camera = new_object_instance(sizeof(t_camera));
	// camera->render = __render;
	camera->vector = vector(0, 0, W_WIDTH, W_HEIGHT);
	camera->render_view = __render_view;
	fthis()->camera = camera;
	fthis()->scene->camera = camera;
	return ((t_object *) camera);
}

