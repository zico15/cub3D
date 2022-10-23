/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object_base.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:12:48 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/14 18:35:58 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OBJECT_BASE_H
# define FT_OBJECT_BASE_H

# include <ft_util.h>

t_object	*this(void);

void		__destroy_ob();
void		__collision_base(t_object *collided);
#endif
