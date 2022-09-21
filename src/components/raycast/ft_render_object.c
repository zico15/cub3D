/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:28:34 by nprimo            #+#    #+#             */
/*   Updated: 2022/09/21 19:46:44 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

void	render_object(t_vector p)
{
	t_vector	pos_obj;
	t_vector	pos_obj_screen;

//   float sx=sp[s].x-px; //temp float variables
//   float sy=sp[s].y-py;
//   float sz=sp[s].z;

//   float CS=cos(degToRad(pa)), SN=sin(degToRad(pa)); //rotate around origin
//   float a=sy*CS+sx*SN; 
//   float b=sx*CS-sy*SN; 
//   sx=a; sy=b;

	pos_obj.x = 2 * GRID_SIZE;
	pos_obj.y = 2 * GRID_SIZE;
	pos_obj_screen.x = (pos_obj.y - p.y) * ft_cos(p.angle) + (pos_obj.x - p.x) * ft_sin(p.angle);
	pos_obj_screen.y = (pos_obj.x - p.x) * ft_cos(p.angle) - (pos_obj.y - p.y) * ft_sin(p.angle);
	pos_obj_screen.x = (pos_obj_screen.x / pos_obj_screen.y) + W_WIDTH / 2;
	pos_obj_screen.y = W_HEIGHT / 2;
	canva()->rectangle(vector(pos_obj_screen.x, pos_obj_screen.y, 10, 10), 0xffffffffff);
}
