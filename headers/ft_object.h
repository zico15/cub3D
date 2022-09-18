/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:12:48 by edos-san          #+#    #+#             */
/*   Updated: 2022/09/18 14:29:29 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OBJECT_H
# define FT_OBJECT_H

# include <ft_util.h>

typedef struct s_object		t_object;
typedef struct s_player		t_player;
typedef struct s_map		t_map;
typedef struct s_nav_mesh	t_nav_mesh;
typedef struct s_nav_node	t_nav_node;
typedef struct s_buffer		t_buffer;
typedef struct s_camera		t_camera;
typedef struct s_door		t_door;

typedef enum e_type_ob
{
	OBJECT,
	SCENE,
	MAP,
	PLAYER,
	WALL
}	t_type;



typedef struct f_image
{
	void	(*rectangle)(void *img, t_vector vector, int color);
	void	(*pixel)(void *img, int x, int y, int color);
	void	(*txt)(char *str, t_vector v, int color);
	void	*(*new)(int w, int h);
}	t_image;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

struct s_buffer
{
	void	*buffer;
	t_data	data;
	void	(*rectangle)(t_vector v, int color);
	void	(*rectangle_border)(t_vector v, int color, int \
	border, int color_border);
	void	(*pixel)(int x, int y, int color);
	int		(*get_color_imge)(t_data	data, int x, int y);
	void	(*image)(t_sprite *sprite);
	void	(*image_sub)(t_sprite *sprite, t_vector sub);
	void	(*object)(t_object *ob);
	void	(*line)(t_vector begin, t_vector end, int color);
};

struct s_object
{
	t_type			type;
	t_sprite		*sprite;
	t_animation		animation;
	t_vector		vector;
	void			(*update)(void);
	void			(*render)(t_buffer *b);
	void			(*destroy)(void *o);
	void			(*funct_key)(int key, int type_event);
	void			(*funct_mouse)(int x, int y, int type_event);
	void			(*colison)(t_object *collided);
	void			(*set_position)(t_vector v);
};

struct s_map
{
	t_type			type;
	t_sprite		*sprite;
	t_animation		animation;
	t_vector		vector;
	void			(*update)(void);
	void			(*render)(t_buffer *b);
	void			(*destroy)(void *o);
	void			(*funct_key)(int key, int type_event);
	void			(*funct_mouse)(int x, int y, int type_event);
	void			(*colison)(t_object *collided);
	void			(*set_position)(t_vector v);
	void			(*load)(char *path);
	char			*f;
	char			*c;
	int				dir;
	void			*map;
	char			**maps;
	t_vector		player;
	t_vector		vector_mini_map;
	int				check[100][100];
	int				is_map_ok;
};

struct s_player
{
	t_type			type;
	t_sprite		*sprite;
	t_animation		animation;
	t_vector		vector;
	void			(*update)(void);
	void			(*render)(t_buffer *b);
	void			(*destroy)(void *o);
	void			(*funct_key)(int key, int type_event);
	void			(*funct_mouse)(int x, int y, int type_event);
	void			(*colison)(t_object *collided);
	void			(*set_position)(t_vector v);
	void			(*atacar)(void);
	t_nav_mesh		*agent;
};

struct s_camera
{
	t_type			type;
	t_sprite		*sprite;
	t_animation		animation;
	t_vector		vector;
	void			(*update)(void);
	void			(*render)(t_buffer	*b);
	void			(*destroy)(void *o);
	void			(*funct_key)(int key, int type_event);
	void			(*funct_mouse)(int x, int y, int type_event);
	void			(*colison)(t_object *collided);
	void			(*set_position)(t_vector v);
	void			(*render_view)(t_element *e, void *o);
};

struct s_door
{
	t_type			type;
	t_sprite		*sprite;
	t_animation		animation;
	t_vector		vector;
	void			(*update)(void);
	void			(*render)(t_buffer	*b);
	void			(*destroy)(void *o);
	void			(*funct_key)(int key, int type_event);
	void			(*funct_mouse)(int x, int y, int type_event);
	void			(*colison)(t_object *collided);
	void			(*set_position)(t_vector v);
	int				is_open;
	int				count;
};


struct s_nav_node
{
	int			x;
	int			y;
	int			v;
	int			g;
	int			h;
	int			f;
	t_nav_node	*previu;
	t_nav_node	*next;
};

struct s_nav_mesh
{
	void		*open;
	void		*close;
	void		*rota;
	t_nav_node	*begin;
	t_vector	start;
	t_vector	dest;
	t_object	*o;
	void		*(*set_destination)(t_vector start, t_vector dest);
};

t_object	*new_object(void);
void		*new_object_instance(size_t size);
t_map		*new_map(void);
t_object	*new_teste(void);
t_player	*new_player(void);
t_object	*new_wall(void);
t_object	*new_menu(void);
t_object	*new_camera(void);
t_object	*new_door(void);

#endif
