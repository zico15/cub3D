/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/19 16:27:21 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCENE_H
# define FT_SCENE_H

# include <ft_util.h>

# define SCENE_EXTENSION ".cub"

typedef struct s_scene	t_scene;

struct s_scene
{
	void		*img;
	int			x;
	int			y;
	int			width;
	int			height;
	int			(*update)(void);
	int			(*render)(void);
	int			(*destroy)(t_object *o);
	char		*f;
	char		*c;
	void		*map;
	void		*objects;
	t_object	*(*add)(t_object *o);
};

t_scene	*new_scene(void *file);

#endif
