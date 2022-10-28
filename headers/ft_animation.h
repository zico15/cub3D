/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:23:31 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/27 14:44:15 by edos-san         ###   ########.fr       */
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

typedef struct s_fanimation
{
	t_animation		*(*create)(t_object *ob, int size);
	void			(*load_animation)(char *fileName, int size, t_animation \
	*animations, double velocity);
	void			(*update_all)(t_object *ob);
	void			(*updated)(t_object *ob, int animation);
	void			(*destroy)(t_object *ob);
	void			(*destroy_size)(t_animation	*a, int size);
}	t_fanimation;

t_sprite		*new_sprite(int w, int h);
t_fanimation	animation(void);

#endif
