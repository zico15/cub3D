/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:57:49 by ezequeil          #+#    #+#             */
/*   Updated: 2022/10/11 18:39:43 by nprimo           ###   ########.fr       */
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
void 	render_view2();

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
	render_view2(*p);
}
