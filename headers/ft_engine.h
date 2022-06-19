/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/19 11:51:56 by edos-san         ###   ########.fr       */
=======
/*   Updated: 2022/06/19 03:04:23 by edos-san         ###   ########.fr       */
>>>>>>> ezequiel
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENGINE_H
# define FT_ENGINE_H

# include <ft_scene.h>

typedef struct s_engine	t_engine;

struct s_engine
{
	void			*mlx;
	void			*win;
	t_scene			*scene;
	void			(*load_scene)(char *patch);
	int				(*close)(char *msg);
};

t_engine	*engine(void);
t_engine	*cread_engine(char *title, int width, int height);

#endif
