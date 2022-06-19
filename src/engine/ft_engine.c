/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/19 02:07:38 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

static int	__close(char *msg)
{
	printf("%s\n", msg);
	exit(0);
	return (0);
}

t_engine	*cread_engine(char *title, int width, int height)
{
	static t_engine	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, width, height, title);
	e.close = __close;
	return (&e);
}
