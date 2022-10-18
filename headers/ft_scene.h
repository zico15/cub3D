/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/18 15:30:04 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCENE_H
# define FT_SCENE_H

# include <ft_util.h>

# define SCENE_EXTENSION ".cub"

typedef struct s_scene	t_scene;
typedef struct s_node	t_node;

struct s_node
{
	int		x;
	int		y;
	int		v;
	void	*nodes;
};

struct s_scene
{
	t_type			type;
	t_sprite		*sprite;
	t_animation		*animation;
	int				size_animation;
	t_vector		vector;
	void			(*update)(void);
	void			(*render)(t_buffer	*b);
	void			(*destroy)(void *o);
	void			(*funct_key)(int *key, int type_event);
	void			(*funct_mouse)(int x, int y, int type_event);
	void			(*collision)(t_object *collided);
	void			(*set_position)(t_vector v);
	t_sprite		*(*get_sprite)(t_ray ray);
	void			*objects;
	void			*render_list;
	void			*updade_list;
	void			*colliders_list;
	void			*key_list;
	void			*mouse_list;
	t_object		*(*add)(void *o);
	int				is_print;
	t_map			*map;
	t_player		*player;
	t_camera		*camera;
	void			*enemies;
};

t_scene	*new_scene(void);

#endif
