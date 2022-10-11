/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:57:49 by ezequeil          #+#    #+#             */
/*   Updated: 2022/10/11 12:22:09 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_object.h>

#define GREEN 0x0000FF00
#define D_GREEN 0x00cc00
#define RED 0x00ff0000
#define D_RED 0x00cc0000
#define WHITE 0x00000000
#define BLACK 0xffffffff

void	render_object(t_vector p);
void 	main_render();

t_texture	init_t(t_ray *ray, t_vector column)
{
	t_texture	t;
	
	t.pos.x = (int) ray->cross.x % 32;
	if (ft_sin(ray->angle) < 0)
		t.pos.x = (int)(31.0 - t.pos.x);
	if (ray->vertical)
	{
		t.pos.x = (int) ray->cross.y % 32;
		if (ft_cos(ray->angle) < 0)
			t.pos.x = (int)(31.0 - t.pos.x);
	}
	t.y_offest = 0;
	t.y_step = 32.0 / (double) column.h;
	if (column.h >= W_HEIGHT)
	{
		t.y_offest = (column.h - W_HEIGHT) / 2.0;
		column.h = W_HEIGHT;
	}
	t.pos.y = t.y_offest * t.y_step;
	return (t);
}

void	print_column(t_ray *ray, t_vector column)
{
	int				color;
	double			y;
	t_texture		t;
	t_sprite		*sprite;


	if (ray->ob == NULL)
			return;
	sprite = ray->ob->get_sprite(*ray);
	t = init_t(ray, column);
	if (column.h >= W_HEIGHT)
		column.h = W_HEIGHT;
	column.y = W_HEIGHT / 2 - column.h / 2;
	y = -1;
	while (++y < column.h)
	{
		color = __get_color_sprite(sprite, (int) t.pos.x, (int) t.pos.y);
		// (canva())->rectangle(vector(column.x, column.y + y, column.w, 1),
		// 		color);
		t.pos.y += t.y_step;
	}
}

void	render_ray(t_ray *ray)
{
	double		dist_perp;
	t_vector	column;
	static int	colors[] = {GREEN, D_GREEN, RED, D_RED};

	if (!ray->ob)
		return ;
	dist_perp = ray->distance * ft_cos(ray->rel_angle);
	column.h = (W_HEIGHT * 20 / dist_perp);
	column.w = W_WIDTH / N_RAYS;
	column.x = ray->pos * column.w;
	print_column(ray, column);
}

void	print_ray_2d(t_ray ray)
{
	int color = 0x000000ff;

	if (ray.vertical)
		color = 0x00ffffff;
	ray.cross.x *= GRID_SIZE;
	ray.cross.y *= GRID_SIZE;
	canva()->line(scene()->player->vector, ray.cross, color);
	printf("Angle: %f vertical: %d\n", ray.angle, ray.vertical);
	if (ray.rel_angle == -VIEW_ANGLE / 2)
		printf("------------\n");
}

void	render_view(t_player *p)
{
	double		rel_angle;
	int			color;
	int			i;

	rel_angle = VIEW_ANGLE / 2;
	i = -1;
	// while (++i <= N_RAYS)
	// {
	// 	color = GREEN;
	// 	get_ray_return(p->vector, rel_angle, i);	
	// 	rel_angle -= (double) VIEW_ANGLE / N_RAYS;
	// }
	// print_ray_2d(get_ray_return(p->vector, VIEW_ANGLE / 2, 0));
	// print_ray_2d(get_ray_return(p->vector, 10, 0));
	// print_ray_2d(get_ray_return(p->vector, 0, 0));
	// print_ray_2d(get_ray_return(p->vector, -10, 0));
	// print_ray_2d(get_ray_return(p->vector, -VIEW_ANGLE / 2, 0));
	main_render();
}
