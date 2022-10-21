/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/18 10:24:53 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTIL_H
# define FT_UTIL_H

# include <math.h>
# include <ft_transform.h>
# include <ft_animation.h>
# include <ft_base_array.h>
# include <ft_string.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <mlx.h>
# include <ft_object.h>
# include <ft_engine.h>
# include <limits.h>
# include <sys/time.h>

# define BUFFER_SIZE 999999
# define PI 3.14159265
# define GRID_SIZE 32
# define GRID_MIN_SIZE 20
# define KEY_W 119
# define KEY_S 115
# define KEY_D 100
# define KEY_A 97
# define KEY_M 109
# define KEY_E 101
# define KEY_SPACE 32
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define EVENT_PRESS 0
# define EVENT_RELEASE 1
# define EVENT_CLICK 2
# define MOVE_LEN 0.08
# define ROTATION_LEN 0.01
# define W_WIDTH 1080
# define W_HEIGHT 860
# define VIEW_ANGLE 50
# define N_RAYS	W_WIDTH
# define COLOR_TRANSPARENT 0xd411aa

typedef struct s_this
{
	t_array			*array;
	t_array			*array_main;
	t_hashmap		*hashmap;
	t_engine		*engine;
	t_scene			*scene;
	t_object		*object;
	t_nav_mesh		*agent;
	t_player		*player;
	t_map			*map;
	t_camera		*camera;
}	t_this;

//			this
t_this		*fthis(void);
t_scene		*scene(void);
t_map		*map(void);

//			util
char		*get_next_line(int fd);
void		__destroy_element_object(t_element	*e);
t_image		image(void);
void		pixel_put_sprite(t_sprite *sprite, int x, int y, int color);
t_sprite	*copy_sprite(t_sprite	*sprite);
int			**baffer_int(void);
void		destroy_sprite(t_sprite *sprite);

//			memory
int			free_ob(void *v);
int			free_list(char **str);
void		*malloc_ob(size_t __size);

//			remove - testes
int			__get_color(void *img, int x, int y);
int			__get_color_sprite(t_sprite *sprite, int x, int y);
int			funct_key_engine(int *key, int type_event);

//			time
double		now(void);
t_ray		get_ray_return(t_vector p, double rel_angle, int pos);
int			random_number(int min_num, int max_num);

#endif
