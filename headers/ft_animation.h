/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:23:31 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/14 18:21:42 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ANIMATION_H
# define FT_ANIMATION_H

# include <ft_util.h>

typedef struct s_sprite
{
	void		*img;
	t_data		data;
	t_vector	v;
}	t_sprite;

typedef struct s_animation
{
	int			index;
	int			size;
	t_sprite	**list;
	int			is_run;
	int			is_repeat;
	double		time;
	double		time_delay;
}	t_animation;

t_sprite	*new_sprite(int w, int h);
void 		update_animation(t_object *ob, int animation);
void 		update_animation_all(t_object *ob);

#endif