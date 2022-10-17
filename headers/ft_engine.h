/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/05 18:14:24 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENGINE_H
# define FT_ENGINE_H

# include <ft_scene.h>

typedef struct s_engine	t_engine;
typedef struct s_buffer	t_buffer;

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
	int				is_key_press;
	int				keys[90000];
	t_buffer		*canva;
	t_scene			*(*add_scene)(t_scene *scene);
	t_scene			*(*set_scene)(int	index_scene);
	t_scene			*(*load_maps)(char **args, int size);
	void			*(*load_img)(t_vector *v, char *file_name);
	t_sprite		*(*load_sprite)(char *file_name);
	int				(*close)(char *msg);
	void			*imags;
};

t_engine	*engine(void);
t_buffer	*canva(void);
t_image		image(void);
t_engine	*cread_engine(char *title, char *path, int width, int height);

#endif
