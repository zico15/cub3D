/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/24 19:44:50 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENGINE_H
# define FT_ENGINE_H

# include <ft_scene.h>

typedef struct s_engine	t_engine;
typedef struct s_buffer	t_buffer;
typedef t_object		*(*t_new_obj)(void);

struct s_engine
{
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
	char			keys[75000];
	t_buffer		*canva;
	t_scene			*(*add_scene)(t_scene *scene);
	t_scene			*(*set_scene)(int	index_scene);
	t_scene			*(*load_maps)(char **args, int size);
	void			*(*load_img)(t_vector *v, char *file_name);
	t_sprite		*(*load_sprite)(char *file_name);
	int				(*close)(char *msg);
	t_new_obj		new_obs[256];
	void			*images;
};

t_engine	*engine(void);
t_buffer	*canva(void);
t_image		image(void);
t_engine	*cread_engine(char *title, int width, int height);

#endif
