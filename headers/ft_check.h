/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/25 15:34:01 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_H
# define FT_CHECK_H

# include <ft_util.h>

void	check_color(t_element *e, void *o);
void	check_map(t_map	*map, int x, int y);
int		check_maps_nodes(t_map *map, t_vector start);
void	destroy_element_node(t_element	*e);
void	destroy_node(t_node	*n);
void	cread_map(t_map *scene);
void	print_check_map(t_map *scene);
#endif
