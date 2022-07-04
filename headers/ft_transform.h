/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:12:48 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/03 20:03:08 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRANSFORM_H
# define FT_TRANSFORM_H

typedef struct s_nav_node	t_nav_node;
typedef struct s_vector		t_vector;

struct s_vector
{
	int			x;
	int			y;
	int			z;
	int			w;
	int			h;
};

t_vector	vector(int x, int y, int w, int h);
t_vector	vector_zero(void);

#endif
