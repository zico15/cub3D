/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:49:58 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/07 21:05:15 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_check.h>

void	destroy_node(t_node	*n)
{
	array(n->nodes)->destroy();
	free_ob(n);
}

void	add_object_scene(double x, double y, char c)
{
	double		angle;
	t_object	*obj;

	angle = 0;
	if (c == '1')
		obj = scene()->add(new_wall());
	else if (string().contains("NSWE", _str(c)))
		obj = scene()->add(new_player());
	else
		return ;
	if (c == 'S')
		angle = 180;
	if (c == 'E')
		angle = 90;
	if (c == 'W')
		angle = -90;
	obj->vector = vector(x * GRID_SIZE, y * GRID_SIZE, GRID_SIZE, GRID_SIZE);
	obj->vector.angle = angle;
	obj->vector.radius = GRID_SIZE;
}

void	destroy_element_node(t_element	*e)
{
	t_node	*n;
	t_array	*this;

	this = fthis()->array;
	n = e->value;
	if (n)
		destroy_node(n);
	array(this);
	free_ob(e->key);
}
