/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine_util.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/03 21:16:09 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENGINE_UTIL_H
# define FT_ENGINE_UTIL_H

int		__funct_key(int key, void *o);
int		__funct_mousse(int keycode, void *vars);
void	__print(t_object *o);
t_scene	*__set_scene(int index_scene);
t_scene	*__load_maps(char **args, int size);
void	*__load_img(t_object *ob, char *file_name);

#endif
