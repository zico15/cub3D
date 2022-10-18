/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:12:48 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/18 18:00:54 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRANSFORM_H
# define FT_TRANSFORM_H

typedef struct s_nav_node	t_nav_node;
typedef struct s_vector		t_vector;
typedef struct s_collision	t_collision;
typedef struct s_ray		t_ray;
typedef struct s_object		t_object;
typedef enum e_face			t_face;
typedef struct s_texture	t_texture;

enum e_face
{
	N,
	E,
	S,
	W
};

struct	s_v
{
	double	x;
	double	y;
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

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

struct s_collision
{
	t_object	*(*collision_ob)(t_object *object, double x, double y);
	int			(*circular)(t_vector a, t_vector b);
	int			(*rectangular)(t_vector a, t_vector b);
	t_object	*(*pixel)(t_object *object, double px, double py);
	t_object	*(*rectangula_ob)(t_object *object, double px, double py);
};

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

struct s_ray
{
	t_vector	camera;
	t_vector	dir;
	t_vector	side_dist;
	t_vector	delta_dist;
	double		cross;
	double		perp_distance;
	t_pos		step;
	t_pos		map_cell;
	int			hit;
	t_object	*obj;
	int			side;
	t_face		face_dir;
};

struct s_texture
{
	t_vector	pos;
	double		y_offset;
	double		y_step;
	int			line_h;
	int			draw_start_y;
	t_vector	draw_start;
	t_vector	draw_end;
};

typedef struct f_image
{
	void	(*rectangle)(void *img, t_vector vector, int color);
	void	(*pixel)(void *img, int x, int y, int color);
	void	(*txt)(char *str, t_vector v, int color);
	void	*(*new)(int w, int h);
}	t_image;

t_vector	vector(double x, double y, double w, double h);
t_vector	vector_grid(t_vector v);
t_vector	vector_grid_size(t_vector v, double w, double h);
int			vector_distance(t_vector a, t_vector b);
t_vector	vector_zero(void);
t_collision	collision(void);
t_vector	*copy_vector(t_vector *v);
double		get_vectors_distance(t_vector a, t_vector b, double angle);
double		ft_cos(double angle);
double		ft_sin(double angle);
double		ft_tan(double angle);
double		ft_atan2(double y, double x);

#endif
