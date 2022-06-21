/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:12:48 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/21 00:46:00 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OBJECT_H
# define FT_OBJECT_H

typedef struct s_object		t_object;
typedef struct s_vector		t_vector;

struct s_vector
{
	int			x;
	int			y;
	int			z;
	int			w;
	int			h;
};

struct s_object
{
	void			*img;
	t_vector		vector;
	int				(*update)(void);
	int				(*render)(void);
	int				(*destroy)(t_object *o);
	void			*asd;
};

struct s_player
{
	int				(*update)(void);
	int				(*render)(void);
	void			(*atacar)(void);
	void			*mlx;
};

t_object	*new_object(void);
t_vector	vector(int x, int y, int w, int h);
t_vector	vector_zero(void);

#endif
