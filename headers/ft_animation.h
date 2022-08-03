/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:23:31 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/03 21:54:05 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ANIMATION_H
# define FT_ANIMATION_H

typedef struct s_sprite
{
	void		*img;
	t_vector	v;
}	t_sprite;

typedef struct s_sprites
{
	t_sprite 	**list;
	int			index;
	int			size;
	int			is_repeat;
}	t_sprites;

typedef struct s_animation
{
	int			index;
	int			size;
	int			is_run;
	t_sprites	*animations;
}	t_animation;

t_sprite 	*new_sprite (int w, int h);
void 		set_animation(t_object *obj, int i);

#endif