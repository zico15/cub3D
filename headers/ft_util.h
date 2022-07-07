/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/07 17:34:29 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTIL_H
# define FT_UTIL_H

# include <math.h>
# include <ft_transform.h>
# include <ft_base_array.h>
# include <ft_string.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <mlx.h>
# include <ft_object.h>
# include <ft_nav_mesh.h>
# include <ft_engine.h>


# define BUFFER_SIZE 999999
# define PI 3.14159265
# define GRID_SIZE 32
# define KEY_W 119
# define KEY_S 115
# define KEY_D 100
# define KEY_A 97
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct s_this
{
	t_array			*array;
	t_array			*array_main;
	t_hashmap		*hashmap;
	t_engine		*engine;
	t_scene			*scene;
	t_object		*object;
	t_nav_mesh		*agent;
	t_map			*map;

}	t_this;

//			this
t_this		*fthis(void);
t_scene		*scene(void);
t_map		*map(void);

//			util
char		*get_next_line(int fd);
void		__destroy_element_object(t_element	*e);

//			memory
int			free_ob(void *v);
int			free_list(char **str);
void		*malloc_ob(size_t __size);

//			remove - testes

#endif
