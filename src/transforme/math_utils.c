/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:49:38 by nprimo            #+#    #+#             */
/*   Updated: 2022/10/24 19:51:06 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

double	ft_cos(double angle)
{
	return (cos(angle * 0.017453293));
}

double	ft_sin(double angle)
{
	return (sin(angle * 0.017453293));
}

double	ft_tan(double angle)
{
	return (tan(angle * 0.017453293));
}

double	ft_atan2(double y, double x)
{
	return (atan2(y, x) * 0.017453293);
}
