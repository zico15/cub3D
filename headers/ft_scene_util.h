/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_util.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/24 19:29:20 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCENE_UTIL_H
# define FT_SCENE_UTIL_H

# include <ft_util.h>

void	check_color(t_element *e, void *o);
void	check_map(t_scene	*scene, int x, int y);
void	__funct_mouse_scene(int x, int y, int type_event);
void	__funct_key_scene(char *key, int type_event);

#endif
