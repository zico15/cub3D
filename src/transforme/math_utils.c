/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:49:38 by nprimo            #+#    #+#             */
/*   Updated: 2022/08/28 12:51:30 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

double	ft_cos(double angle)
{
	double	val;

	val = M_PI / 180;
	return (cos(angle * val));
}

double	ft_sin(double angle)
{
	double	val;

	val = M_PI / 180;
	return (sin(angle * val));
}

double	ft_tan(double angle)
{
	double	val;

	val = M_PI / 180;
	return (tan(angle * val));
}
