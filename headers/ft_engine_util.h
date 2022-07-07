/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine_util.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/07 12:25:47 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENGINE_UTIL_H
# define FT_ENGINE_UTIL_H

# include <ft_util.h>

int		__funct_key_engine(int key, void *o);
int		__funct_mousse_engine(int keycode, void *vars);
t_scene	*__set_scene(int index_scene);
t_scene	*__load_maps(char **args, int size);
void	*__load_img(t_object *ob, char *file_name);
void	__pixel_put_win(int x, int y, int color);

#endif
