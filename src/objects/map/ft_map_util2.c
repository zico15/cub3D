/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_util2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:00:43 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/23 21:03:57 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>

void	__destroy_ob_map(void)
{
	t_map	*m;
	void	*list;

	m = (t_map *) this();
	list = fthis()->array;
	__destroy_ob();
	free_ob(m->f);
	free_ob(m->c);
	array(m->file)->destroy();
	destroy_sprite(m->sprite);
	free_ob(m->maps);
	free_list((void **) m->maps_ob);
	fthis()->array = list;
}

void	__render_map(t_buffer	*b)
{
	b->rectangle(vector(0, 0, W_WIDTH, W_HEIGHT / 2), map()->c_color);
	b->rectangle(vector(0, W_HEIGHT / 2, W_WIDTH, W_HEIGHT / 2), \
	map()->f_color);
}
