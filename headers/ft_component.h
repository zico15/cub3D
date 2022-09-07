/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_component.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/09/07 18:51:26 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMPONENT_H
# define FT_COMPONENT_H

# include <ft_util.h>
# include <ft_nav_mesh.h>


void	render_view(t_player *p);
void	update_print_ray(t_vector p, double rel_angle, void *ray_return, int max);

#endif
