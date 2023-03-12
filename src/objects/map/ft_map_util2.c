/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_util2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:00:43 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/12 14:47:23 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>

void	__destroy_ob_map(void)
{
	t_map	*m;

	m = (t_map *) this();
	free_list((void **) m->maps);
	m->maps = NULL;
	free_list((void **) m->check_maps);
	m->check_maps = NULL;
	__destroy_ob();
	destroy_sprite(m->sprite);
	free_list((void **) m->maps_ob);
}

void	__render_map(t_buffer	*b)
{
	b->rectangle(vector(0, 0, win()->w, win()->h / 2), map()->c_color);
	b->rectangle(vector(0, win()->h / 2, win()->w, win()->h / 2), \
	map()->f_color);
}
