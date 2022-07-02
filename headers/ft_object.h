/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:12:48 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/02 00:04:55 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OBJECT_H
# define FT_OBJECT_H

typedef struct s_object		t_object;
typedef struct s_vector		t_vector;
typedef struct s_map		t_map;

typedef enum e_type_ob
{
	OBJECT,
	SCENE,
	MAP,
	PLAYER
}	t_type;

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
	t_type			type;
	void			*img;
	t_vector		vector;
	void			(*update)(void);
	void			(*render)(void);
	void			(*destroy)(void *o);
	void			(*funct_key)(int key, int type_event);
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
	void			(*atacar)(void);
	void			*mlx;
};

t_object	*new_object(void);
void		*new_object_instance(size_t size);
void		*new_map(char *path);
void		*new_teste(void);
t_vector	vector(int x, int y, int w, int h);
t_vector	vector_zero(void);

#endif
