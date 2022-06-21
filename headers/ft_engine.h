/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/20 22:53:42 by edos-san         ###   ########.fr       */
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
	void			(*load_scene)(char *path);
	int				(*close)(char *msg);
};

struct s_render
{
	void			(*print_ob)(t_object *o);
	void			(*pixel_put)(t_data *data, int x, int y, int color);
	void			(*pixel_put_rec)(t_data *data, int color, t_vector vector);
};

t_engine	*engine(void);
t_render	render(void);
t_engine	*cread_engine(char *title, char *path, int width, int height);

#endif
