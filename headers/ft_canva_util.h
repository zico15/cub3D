/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canva_util.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/31 21:53:29 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CANVA_UTIL_H
# define FT_CANVA_UTIL_H

# include <ft_util.h>

void	__rectangle(t_vector v, int color);
void	__pixel(int x, int y, int color);
int		__get_color_imge(t_data	data, int x, int y);
void	__image(t_vector v, void *img);
void	__image_sub(t_vector v, void *img, t_vector sub);
void	__object(t_object *ob);

#endif
