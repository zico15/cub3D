/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/19 02:13:56 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENGINE_H
# define FT_ENGINE_H

# include <ft_util.h>
# include <ft_scene.h>

typedef struct s_engine	t_engine;

struct s_engine
{
	void			*mlx;
	void			*win;
	t_scene			*scene;
	int				(*close)(char *msg);
};

t_engine	*cread_engine(char *title, int width, int height);

#endif
