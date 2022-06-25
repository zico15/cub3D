/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/25 15:33:44 by edos-san         ###   ########.fr       */
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
	void			(*destroy)(t_object *o);
	void			*objects;
	t_object		*(*add)(t_object *o);
};

t_scene	*new_scene(void);

#endif
