/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:12:48 by edos-san          #+#    #+#             */
/*   Updated: 2022/09/18 10:56:41 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRANSFORM_H
# define FT_TRANSFORM_H

typedef struct s_nav_node	t_nav_node;
typedef struct s_vector		t_vector;
typedef struct s_colison	t_colison;
typedef struct s_ray		t_ray;
typedef struct s_object		t_object;
typedef enum e_face			t_face;

enum e_face
{
	N,
	E,
	S,
	W
};

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
	t_object	*(*pixel)(t_object *object, double px, double py);
};

struct s_ray
{
	t_vector	cross;
	t_vector	offset;
	int			collision;
	double		distance;
	int			vertical;
	t_face		direction;
	double		angle;
};

t_vector	vector(double x, double y, double w, double h);
t_vector	vector_zero(void);
t_colison	colison(void);
t_vector	*copy_vector(t_vector *v);
double		get_vectors_distance(t_vector a, t_vector b, double angle);
double		ft_cos(double angle);
double		ft_sin(double angle);
double		ft_tan(double angle);

#endif
