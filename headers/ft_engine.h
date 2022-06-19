/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/19 15:53:20 by edos-san         ###   ########.fr       */
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
	void			*scenes;
	void			(*load_scene)(char *patch);
	int				(*close)(char *msg);
	void			(*print)(t_object *o);
};

t_engine	*engine(void);
t_engine	*cread_engine(char *title, int width, int height);

#endif
