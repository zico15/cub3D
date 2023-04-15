/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:44:15 by edos-san          #+#    #+#             */
/*   Updated: 2023/04/12 17:34:42 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <stdio.h>
#include <stdint.h>

t_vector	vector_grid_size(t_vector v, double w, double h)
{
	v.x = (v.x * map()->grid_width);
	v.y = (v.y * map()->grid_height);
	v.w = w;
	v.h = h;
	return (v);
}

int	vector_distance(t_vector a, t_vector b)
{
	int		x;
	int		y;

	x = a.x - b.x;
	if (x < 0)
		x *= -1;
	y = a.y - b.y;
	if (y < 0)
		y *= -1;
	return (x + y);
}



char	*dtostrf(double val, unsigned char prec, char *sout)
{
	uint32_t	iPart;
	uint32_t	dPart;

	iPart = (uint32_t)val;
	dPart = (uint32_t)((val - (double)iPart) * pow(10, prec));
	sprintf(sout, "%d.%d", iPart, dPart);
  	return (sout);
}

char	*vector_to_string(t_vector *v)
{
	static char	buffer[40];

	dtostrf(v->x, 3, buffer);
	buffer[3] = ',';
	gcvt(v->y, 3, &buffer[4]);
	buffer[7] = 0;
	return (buffer);
}

t_vector	*new_vector(double x, double y)
{
	t_vector	*tmp;

	tmp = malloc_ob(sizeof(t_vector));
	tmp->x = x;
	tmp->y = y;
	return (tmp);
}
