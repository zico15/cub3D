/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alfabeto.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:30:58 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/27 15:16:29 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

void	laod_alfabeto(void)
{
	t_animation	*a;
	int			i;

	a = (animation()).create(NULL, 1);
	(animation()).load_animation("imgs/alfabeto/tile00.xpm", 41, \
	&a[0], 1);
	i = -1;
	(void) i;
	while (++i < 256)
		engine()->alfabeto[i] = a[0].list[38];
	i = -1;
	while (++i < 26)
	{
		engine()->alfabeto[i + 'A'] = a[0].list[i];
		engine()->alfabeto[i + 'a'] = a[0].list[i];
	}
	i = -1;
	while (++i < 10)
		engine()->alfabeto[i + '0'] = a[0].list[i + 25];
	engine()->alfabeto[(int) '.'] = a[0].list[38];
	engine()->alfabeto[(int) '_'] = a[0].list[37];
	engine()->alfabeto[0] = a[0].list[40];
	engine()->alfabeto[1] = a[0].list[39];
	(animation()).destroy_size(a, 1);
}
