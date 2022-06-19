/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/19 13:27:32 by edos-san         ###   ########.fr       */
=======
/*   Updated: 2022/06/19 03:11:51 by edos-san         ###   ########.fr       */
>>>>>>> ezequiel
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCENE_H
# define FT_SCENE_H

# include <ft_util.h>

# define SCENE_EXTENSION ".cub"

typedef struct s_scene	t_scene;

struct s_scene
{
<<<<<<< HEAD
	int			(*update)(void);
	int			(*render)(void);
	char		*f;
	char		*c;
	void		**map;
=======
	void	*file;
	char	*f;
	char	*c;
	void	**map;
	int		(*close)(char *msg);
>>>>>>> ezequiel
};

t_scene	*new_scene(void *file);

#endif
