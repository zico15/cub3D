/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canva_util.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/08 16:15:12 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CANVA_UTIL_H
# define FT_CANVA_UTIL_H

# include <ft_util.h>

void	__rectangle(t_vector v, int color);
void	__rectangle_border(t_vector v, int color, int border, int color_border);
void	__pixel(int x, int y, int color);
int		__get_color_img(t_data	data, int x, int y);
void	__image(t_sprite *sprite);
void	__image_sub(t_sprite *sprite, t_vector sub);
void	__object(t_object *ob);
void	__draw_line(t_vector begin, t_vector end, int color);
void	__triangle(t_vector pos, t_vector dir, t_vector perp_dir, int color);
void	__image_resize_buffer(t_sprite *buffer, t_sprite *sprite);

#endif
