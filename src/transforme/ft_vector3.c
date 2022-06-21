/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:44:15 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/20 22:55:48 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

t_vector	vector(int x, int y, int w, int h)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.w = w;
	v.h = h;
	return (v);
}

t_vector	vector_zero(void)
{
	t_vector	v;

	v.x = 0;
	v.y = 0;
	v.z = 0;
	v.w = 0;
	v.h = 0;
	return (v);
}
