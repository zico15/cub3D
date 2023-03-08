/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:12:48 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/08 16:42:24 by edos-san         ###   ########.fr       */
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
typedef struct s_enemy		t_enemy;
typedef struct s_menu		t_menu;
typedef struct s_portal		t_portal;

typedef enum e_type_ob
{
	OBJECT,
	SCENE,
	MAP,
	PLAYER,
	WALL,
	DOOR,
	ENEMY,
	COLLECTABLE,
	MENU
}	t_type;

struct s_buffer
{
	void	*buffer;
	t_data	data;
	void	(*rectangle)(t_vector v, int color);
	void	(*rectangle_border)(t_vector v, int color, int \
	border, int color_border);
	void	(*pixel)(int x, int y, int color);
	int		(*get_color_img)(t_data	data, int x, int y);
	void	(*image)(t_sprite *sprite);
	void	(*image_pos)(t_sprite *sprite, int x1, int y1);
	void	(*image_sub)(t_sprite *sprite, t_vector sub);
	void	(*object)(t_object *ob);
	void	(*line)(t_vector begin, t_vector end, int color);
	void	(*image_resize)(t_sprite *sprite, double width, double height);
	void	(*triangle)(t_vector pos, t_vector dir, \
	t_vector perp_dir, int color);
	void	(*image_resize_buffer)(t_sprite *buffer, t_sprite *sprite);
};

struct s_object
{
	t_type			type;
	t_sprite		*sprite;
	t_animation		*animation;
	int				size_animation;
	t_vector		vector;
	double			life;
	void			(*update)(void);
	void			(*render)(t_buffer *b);
	void			(*destroy)();
	void			(*funct_key)(char *key, int type_event);
	void			(*funct_mouse)(int x, int y, int type_event);
	void			(*collision)(t_object *collided);
	int				(*set_position)(t_vector v);
	t_sprite		*(*get_sprite)(t_ray ray);
	int				(*damage)(double	d);
};

struct s_portal
{
	t_type			type;
	t_sprite		*sprite;
	t_animation		*animation;
	int				size_animation;
	t_vector		vector;
	double			life;
	void			(*update)(void);
	void			(*render)(t_buffer *b);
	void			(*destroy)();
	void			(*funct_key)(char *key, int type_event);
	void			(*funct_mouse)(int x, int y, int type_event);
	void			(*collision)(t_object *collided);
	int				(*set_position)(t_vector v);
	t_sprite		*(*get_sprite)(t_ray ray);
	int				(*damage)(double	d);
	int				action;
	double			time_action;
	t_sprite		*sprits_wall[4];
};

struct s_map
{
	t_type			type;
	t_sprite		*sprite;
	t_animation		*animation;
	int				size_animation;
	t_vector		vector;
	double			life;
	void			(*update)(void);
	void			(*render)(t_buffer *b);
	void			(*destroy)();
	void			(*funct_key)(char *key, int type_event);
	void			(*funct_mouse)(int x, int y, int type_event);
	void			(*collision)(t_object *collided);
	int				(*set_position)(t_vector v);
	t_sprite		*(*get_sprite)(t_ray ray);
	int				(*damage)(double	d);
	void			(*load)(char *path);
	void			*file;
	char			**maps;
	char			**check_maps;
	t_vector		player;
	t_vector		vector_mini_map;
	int				ckeck_file[7];
	t_sprite		*sprits_wall[4];
	int				is_map_ok;
	int				c_color;
	int				f_color;
	int				size_width;
	int				size_height;
	int				grid_width;
	int				grid_height;
	int				is_print;
	t_object		*(*get_object)(int x, int y);
	t_object		***maps_ob;
	int				count_player;
};

struct s_player
{
	t_type			type;
	t_sprite		*sprite;
	t_animation		*animation;
	int				size_animation;
	t_vector		vector;
	double			life;
	void			(*update)(void);
	void			(*render)(t_buffer *b);
	void			(*destroy)();
	void			(*funct_key)(char *key, int type_event);
	void			(*funct_mouse)(int x, int y, int type_event);
	void			(*collision)(t_object *collided);
	int				(*set_position)(t_vector v);
	t_sprite		*(*get_sprite)(t_ray ray);
	int				(*damage)(double	d);
	t_vector		dir;
	t_vector		plane;
	t_object		*mira;
};

struct s_enemy
{
	t_type			type;
	t_sprite		*sprite;
	t_animation		*animation;
	int				size_animation;
	t_vector		vector;
	double			life;
	void			(*update)(void);
	void			(*render)(t_buffer *b);
	void			(*destroy)();
	void			(*funct_key)(char *key, int type_event);
	void			(*funct_mouse)(int x, int y, int type_event);
	void			(*collision)(t_object *collided);
	int				(*set_position)(t_vector v);
	t_sprite		*(*get_sprite)(t_ray ray);
	int				(*damage)(double	d);
	t_nav_mesh		*agent;
	double			time;
};

struct s_camera
{
	t_type			type;
	t_sprite		*sprite;
	t_animation		*animation;
	int				size_animation;
	t_vector		vector;
	double			life;
	void			(*update)(void);
	void			(*render)(t_buffer	*b);
	void			(*destroy)();
	void			(*funct_key)(char *key, int type_event);
	void			(*funct_mouse)(int x, int y, int type_event);
	void			(*collision)(t_object *collided);
	int				(*set_position)(t_vector v);
	t_sprite		*(*get_sprite)(t_ray ray);
	int				(*damage)(double	d);
	void			(*render_view)(t_element *e, void *o);
	double			perp_distance_wall[2500];
};

struct s_door
{
	t_type			type;
	t_sprite		*sprite;
	t_animation		*animation;
	int				size_animation;
	t_vector		vector;
	double			life;
	void			(*update)(void);
	void			(*render)(t_buffer	*b);
	void			(*destroy)();
	void			(*funct_key)(char *key, int type_event);
	void			(*funct_mouse)(int x, int y, int type_event);
	void			(*collision)(t_object *collided);
	int				(*set_position)(t_vector v);
	t_sprite		*(*get_sprite)(t_ray ray);
	int				(*damage)(double	d);
	int				is_open;
	int				is_run;
	int				count;
	double			time;
	double			delay;
	int				count_max;
	t_sprite		*sprite_animation;
};

struct s_menu
{
	t_type			type;
	t_sprite		*sprite;
	t_animation		*animation;
	int				size_animation;
	t_vector		vector;
	double			life;
	void			(*update)(void);
	void			(*render)(t_buffer *b);
	void			(*destroy)();
	void			(*funct_key)(char *key, int type_event);
	void			(*funct_mouse)(int x, int y, int type_event);
	void			(*collision)(t_object *collided);
	int				(*set_position)(t_vector v);
	t_sprite		*(*get_sprite)(t_ray ray);
	int				(*damage)(double	d);
	t_sprite		*background;
	t_vector		mouse;
	int				mouse_event;
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
	void		*path;
	void		*memory;
	t_nav_node	*begin;
	t_vector	start;
	t_vector	dest;
	t_object	*ob;
	double		velocity;
	double		delay;
	void		(*clear)();
	void		(*destroy)();
	void		*(*set_destination)(t_vector start, t_vector dest);
};

t_object	*new_object(void);
void		*new_object_instance(size_t size);
t_object	*new_map(void);
t_object	*new_enemy(void);
t_object	*new_player(void);
t_object	*new_wall(void);
t_object	*new_menu(void);
t_object	*new_camera(void);
t_object	*new_door(void);
t_object	*new_barrel(void);
t_object	*new_kit(void);
t_object	*new_portal(void);
t_object	*new_menu_initial(void);

#endif
