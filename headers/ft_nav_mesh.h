/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nav_mesh.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/03 20:44:22 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NAV_MESH_H
# define FT_NAV_MESH_H

# include <ft_util.h>

t_nav_node	*create_nav_node(t_nav_mesh *agent, t_nav_node *previu, t_vector v);
int			check_case_node(t_nav_mesh *agent, t_vector v, int check_value);
void		nav_render(void);
t_nav_mesh	*new_nav_mesh(void);
void		free_nav_mash_list(t_nav_mesh *agent);

#endif
