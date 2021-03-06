/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/09 12:47:40 by ezequeil         ###   ########.fr       */
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
int		check_case(t_map *map, t_vector v, int check_value);
t_node	*create_node(int x, int y, int v);
void	add_object_all_map(t_map *map);
void	add_object_scene(double x, double y, char c);

#endif
