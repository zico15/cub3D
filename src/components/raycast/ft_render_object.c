/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:28:34 by nprimo            #+#    #+#             */
/*   Updated: 2022/09/22 21:30:02 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

void	render_object(t_vector p)
{
	t_vector	pos_obj;
	t_vector	rel_pos;
	t_vector	pos_screen;
	double		angle_rel;

//   float sx=sp[s].x-px; //temp float variables
//   float sy=sp[s].y-py;
//   float sz=sp[s].z;

	pos_obj.x = 4 * GRID_SIZE;
	pos_obj.y = 4 * GRID_SIZE;
//   float CS=cos(degToRad(pa)), SN=sin(degToRad(pa)); //rotate around origin
//   float a=sy*CS+sx*SN; 
//   float b=sx*CS-sy*SN; 
//   sx=a; sy=b;
	angle_rel = - ft_atan2((-p.y + pos_obj.y), (-p.x + pos_obj.x));
	printf("Angle %f\n", (angle_rel - p.angle));
//   sx=(sx*108.0/sy)+(120/2); //convert to screen x,y
//   sy=(sz*108.0/sy)+( 80/2);

//   int scale=32*80/b;   //scale sprite based on distance
//   if(scale<0){ scale=0;} if(scale>120){ scale=120;} 

	rel_pos.y = (pos_obj.x - p.x) * ft_cos(p.angle) - (pos_obj.y - p.y) * ft_sin(p.angle);
	rel_pos.x = (pos_obj.x - p.x) * ft_sin(p.angle) + (pos_obj.y - p.y) * ft_cos(p.angle);
	// rel_pos.x = pos_obj.y * ft_cos(p.angle) + pos_obj.x * ft_sin(p.angle);
	// rel_pos.y = pos_obj.x * ft_cos(p.angle) - pos_obj.y * ft_sin(p.angle);

	if ((angle_rel - p.angle) > -(VIEW_ANGLE / 2) && (angle_rel - p.angle) < (VIEW_ANGLE / 2))
	{	
		pos_screen.x = ((angle_rel - p.angle) * W_WIDTH / 60) / VIEW_ANGLE + W_WIDTH / 2;
		pos_screen.y = W_HEIGHT / 2;
		if (pos_screen.x > 0 && pos_screen.x < W_WIDTH)
			canva()->rectangle(vector(pos_screen.x, pos_screen.y, 10, 10), 0xffffffffff);
		// pos_screen.x = (rel_pos.y * ft_tan((double) VIEW_ANGLE / 2.0)) + rel_pos.x + W_WIDTH / 2;
		// pos_screen.y = W_HEIGHT / 2;
		// if (pos_screen.x > 0 && pos_screen.x < W_WIDTH)
		// // printf("screen pos: %f %f\n", pos_screen.x, pos_screen.y);
		// 	canva()->rectangle(vector(pos_screen.x, pos_screen.y, 10, 10), 0xffffffffff);
	}
}
