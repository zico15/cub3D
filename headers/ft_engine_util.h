/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine_util.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/14 18:42:33 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENGINE_UTIL_H
# define FT_ENGINE_UTIL_H

# include <ft_util.h>

int			__funct_key_press(int key, void *o);
int			__funct_key_release(int key, void *o);
int			__funct_mousse_engine(int keycode, void *vars);
t_scene		*__set_scene(int index_scene);
t_scene		*__load_maps(char **args, int size);
void		*__load_img(t_vector *v, char *file_name);
void		__pixel_put_win(int x, int y, int color);
t_buffer	*__canva(void);
t_sprite	*__load_sprite(char *file_name);

#endif
