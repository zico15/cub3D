/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:12:48 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/19 13:26:19 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OBJECT_H
# define FT_OBJECT_H

typedef struct s_object	t_object;

struct s_object
{
	int				(*update)(void);
	int				(*render)(void);
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

#endif
