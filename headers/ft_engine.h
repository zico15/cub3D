/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2023/04/17 21:43:35 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENGINE_H
# define FT_ENGINE_H

# include <ft_scene.h>
# include <ft_socket.h>

# define MAP_DEBUG 0

typedef struct s_engine	t_engine;
typedef struct s_buffer	t_buffer;
typedef t_object		*(*t_new_obj)(void);

typedef struct s_world
{
	struct timeval	timer;
	int				fps;
	int				frames_rate;
	int				fps_counter;
	double			world_time;
	double			last_time;
	double			last_door;
	double			delta_time;
}	t_world;

struct s_engine
{
	t_world			world;
	void			*mlx;
	void			*win;
	void			*scenes;
	t_map			*map;
	int				index_scene;
	int				width;
	int				height;
	double			delta;
	int				is_game;
	int				is_key_press;
	int				is_mouse_press;
	char			keys[75000];
	char			**args;
	int				maps[50];
	int				size_maps;
	t_vector		v;
	t_buffer		*canva;
	t_scene			*(*add_scene)(t_scene *scene);
	t_scene			*(*set_scene)(int	index_scene);
	t_scene			*(*load_maps)(char **args, int size);
	void			*(*load_img)(t_vector *v, char *file_name);
	t_sprite		*(*load_sprite)(char *file_name);
	int				(*close)(char *msg);
	void			(*player_sound)(char *file);
	t_new_obj		new_obs[256];
	void			*images;
	t_sprite		*alfabeto[256];
	t_sprite		*(*new_sprite)(int w, int h);
	t_socket		*socket;
	void			*clients;
};

t_vector	*win(void);
t_engine	*engine(void);
t_buffer	*canva(void);
t_image		image(void);
t_engine	*cread_engine(char *title);
void		send_position(t_player *ob);
void		send_rotation(t_player *ob);
void		new_client(const char **data);
void		set_client_position(const char **data);
void		connect_client(t_player *ob);

#endif
