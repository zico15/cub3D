/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2023/04/17 19:56:27 by edos-san         ###   ########.fr       */
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
	double			life;
	void			(*update)(void);
	void			(*render)(t_buffer	*b);
	void			(*destroy)();
	void			(*funct_key)(char *key, int type_event);
	void			(*funct_mouse)(int x, int y, int type_event);
	void			(*collision)(t_object *collided);
	int				(*set_position)(t_vector v);
	t_sprite		*(*get_sprite)(t_ray ray);
	int				(*damage)(double	d);
	void			*objects;
	void			*render_list;
	void			*updade_list;
	void			*colliders_list;
	void			*key_list;
	void			*mouse_list;
	void			*remove_object_list;
	t_object		*(*add)(void *o);
	int				is_print;
	t_map			*map;
	t_player		*player;
	t_camera		*camera;
	void			*free_objects;
	void			(*remove_object)(t_object *ob);
	void			(*add_client)(char *fd, double x, double y);
};

t_scene	*new_scene(void);
void	scene_remove_objects_list(void);

#endif
