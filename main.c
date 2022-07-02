/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:29:37 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/02 00:15:19 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

int	main(int argc, char **argv)
{
	t_engine	*e;
	int			fd;

	if (argc < 2)
		printf("ERROR ARG!\n");
	e = cread_engine("cub3D", argv[1], 1200, 600);
	e->load_maps(argv, argc);
	scene()->add(new_teste());
	mlx_hook(e->win, 17, 0, e->close, "exit");
	return (mlx_loop(e->mlx));
}
