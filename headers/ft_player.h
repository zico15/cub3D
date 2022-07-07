/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:23:21 by ezequeil          #+#    #+#             */
/*   Updated: 2022/07/07 18:19:19 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PLAYER_H
# define FT_PLAYER_H

# include <ft_util.h>

void		__funct_key(int key, int type_event);
void		__funct_mouse(int x, int y, int type_event);
void		__set_position(t_vector v);
t_nav_mesh	nav_mesh(t_nav_mesh	*agent);

#endif
