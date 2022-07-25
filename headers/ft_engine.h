/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/09 19:59:41 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENGINE_H
# define FT_ENGINE_H

# include <ft_scene.h>

typedef struct s_engine	t_engine;
typedef struct s_render	t_render;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

struct s_engine
{
	void			*mlx;
	void			*win;
	void			*scenes;
	t_map			*map;
	int				index_scene;
	int 			width;
	int				height;
	t_scene			*(*add_scene)(t_scene *scene);
	t_scene			*(*set_scene)(int	index_scene);
	t_scene			*(*load_maps)(char **args, int size);
	void			*(*load_img)(t_vector *v, char *file_name);
	int				(*close)(char *msg);
};

struct s_render
{
	void			(*print_ob)(t_object *o);
	void			(*pixel_put)(void *img, int x, int y, int color);
	void			(*pixel_put_rec)(void *img, int color, t_vector vector);
	void			(*print_txt)(char *str, t_vector v, int color);
	void			(*pixel_put_win)(int x, int y, int color);
};

t_engine	*engine(void);
t_render	render(void);
t_engine	*cread_engine(char *title, char *path, int width, int height);

#endif
