/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:12:48 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/09 20:04:46 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRANSFORM_H
# define FT_TRANSFORM_H

typedef struct s_nav_node	t_nav_node;
typedef struct s_vector		t_vector;
typedef struct s_colison	t_colison;
typedef struct s_object		t_object;

struct s_vector
{
	double			x;
	double			y;
	double			z;
	double			w;
	double			h;
	double			angle;
	double			radius;
};

struct s_colison
{
	t_object	*(*colison_ob)(t_object *object, double x, double y);
	int			(*circular)(t_vector a, t_vector b);
	int			(*rectangular)(t_vector a, t_vector b);
	int			(*pixel)(t_object *object, double px, double py);
};

t_vector	vector(double x, double y, double w, double h);
t_vector	vector_zero(void);
t_colison	colison(void);

#endif
