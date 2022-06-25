/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:12:48 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/25 15:47:34 by edos-san         ###   ########.fr       */
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
	void			(*destroy)(t_object *o);
};

struct s_map
{
	t_type			type;
	void			*img;
	t_vector		vector;
	void			(*update)(void);
	void			(*render)(void);
	void			(*destroy)(t_object *o);
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
	void			(*destroy)(t_object *o);
	void			(*atacar)(void);
	void			*mlx;
};

t_object	*new_object(void);
void		*new_object_instance(size_t size);
void		*new_map(char *path);
t_vector	vector(int x, int y, int w, int h);
t_vector	vector_zero(void);

#endif
