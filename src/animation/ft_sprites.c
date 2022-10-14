/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:22:21 by nprimo            #+#    #+#             */
/*   Updated: 2022/10/14 18:22:23 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

t_sprite	*new_sprite(int w, int h)
{
	t_sprite	*s;

	s = malloc_ob(sizeof(t_sprite));
	s->v.w = w;
	s->v.h = h;
	s->img = image().new(w, h);
	return (s);
}
