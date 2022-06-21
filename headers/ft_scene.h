/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/21 16:33:34 by edos-san         ###   ########.fr       */
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
	void		*img;
	t_vector	vector;
	int			(*update)(void);
	int			(*render)(void);
	int			(*destroy)(t_object *o);
	char		*f;
	char		*c;
	int			dir;
	void		*map;
	char		**maps;
	int			check[100][100];
	void		*objects;
	t_vector	player;
	t_object	*(*add)(t_object *o);
};

t_scene	*new_scene(void *file);
void	cread_map(t_scene *scene);
void	print_check_map(t_scene *scene);
int		check_maps_nodes(t_scene *scene, t_vector start);

#endif
