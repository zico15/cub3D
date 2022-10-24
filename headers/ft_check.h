/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/24 20:47:06 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_H
# define FT_CHECK_H

# include <ft_util.h>

void	check_color(t_element *e, void *o);
void	check_map(t_map	*map, int x, int y);
void	destroy_element_node(t_element	*e);
void	print_check_map(t_map *scene);
t_node	*create_node(int x, int y, int v);
void	add_object_all_map(t_map *map);

#endif
