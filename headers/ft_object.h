/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:12:48 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/15 15:00:52 by ezequeil         ###   ########.fr       */
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

typedef enum e_type_ob
{
	OBJECT,
	SCENE,
	MAP,
	PLAYER,
	WALL
}	t_type;

struct s_object
{
	t_type			type;
	void			*img;
	t_vector		vector;
	void			(*update)(void);
	void			(*render)(void);
	void			(*destroy)(void *o);
	void			(*funct_key)(int key, int type_event);
	void			(*funct_mouse)(int x, int y, int type_event);
	void			(*colison)(t_object *collided);
	void			(*set_position)(t_vector v);
};

struct s_map
{
	t_type			type;
	void			*img;
	t_vector		vector;
	void			(*update)(void);
	void			(*render)(void);
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
	int				check[100][100];
	int				is_map_ok;
};

struct s_player
{
	t_type			type;
	void			*img;
	t_vector		vector;
	void			(*update)(void);
	void			(*render)(void);
	void			(*destroy)(void *o);
	void			(*funct_key)(int key, int type_event);
	void			(*funct_mouse)(int x, int y, int type_event);
	void			(*colison)(t_object *collided);
	void			(*set_position)(t_vector v);
	void			(*atacar)(void);
	t_nav_mesh		*agent;
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

#endif
