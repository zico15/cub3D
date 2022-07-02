/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_mash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:37:26 by ezequeil          #+#    #+#             */
/*   Updated: 2022/07/02 00:14:27 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

static void	expand(t_map *map, t_node *n, int size_w, int size_h)
{
	if (!n)
		return ;
	if (check_case(map, vector(n->x, n->y + 1, size_w, size_h), n))
		(array(n->nodes))->add(create_node(n->x, n->y + 1, n->v + 1));
	if (check_case(map, vector(n->x + 1, n->y, size_w, size_h), n))
		(array(n->nodes))->add(create_node(n->x + 1, n->y, n->v + 1));
	if (check_case(map, vector(n->x, n->y - 1, size_w, size_h), n))
		(array(n->nodes))->add(create_node(n->x, n->y - 1, n->v + 1));
	if (check_case(map, vector(n->x - 1, n->y, size_w, size_h), n))
		(array(n->nodes))->add(create_node(n->x - 1, n->y, n->v + 1));
}

void *generation(t_map *map, t_vector start, t_vector dest)
{
    printf("start: %i / %i dest: %i / %i\n", start.x, start.y, dest.x, dest.y);
    return (NULL);
}