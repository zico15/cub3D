/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/03 21:18:35 by ezequeil         ###   ########.fr       */
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
	void			*img;
	t_vector		vector;
	void			(*update)(void);
	void			(*render)(void);
	void			(*destroy)(void *o);
	void			(*funct_key)(int key, int type_event);
	void			(*funct_mouse)(int x, int y, int type_event);
	void			*objects;
	void			*key_list;
	void			*mouse_list;
	t_object		*(*add)(void *o);
	int				is_print;
};

t_scene	*new_scene(void);

#endif
