/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:20:00 by nprimo            #+#    #+#             */
/*   Updated: 2022/08/01 12:54:21 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>

#define GREEN 0x0000FF00

static void	__render_column(t_buffer *b, t_object *p, \
t_vector obj, int ray_count)
{
	t_vector	column;
	double		distance;


	distance = get_vectors_distance(p->vector, obj);
	column.h = W_HEIGHT / (distance);
	column.w = W_WIDTH / VIEW_ANGLE;
	column.x = (ray_count * column.w);
	// column.x = (ray_count * column.w) + p->vector.x;
	column.y = W_HEIGHT / 2 + column.h / 2;
	//b->rectangle(column, GREEN);
}

static void	__render_view(t_element *e, void *o)
{
	int			ray_count;
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
	//camera->render = __render;
	camera->vector = vector(0, 0, W_WIDTH, W_HEIGHT);
	camera->render_view = __render_view;
	fthis()->camera = camera;
	fthis()->scene->camera = camera;
	return ((t_object *) camera);
}

