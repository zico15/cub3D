/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:29:37 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/14 12:23:07 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

int	main(int argc, char **argv)
{
	t_engine		*e;


	if (argc < 2 || argc >= 50)
	{
		printf("ERROR ARG!\n");
		return ((*argv != NULL));
	}
	e = cread_engine("cub3D");
	e->world.timer = get_time();
	e->load_maps(argv, argc);
	if (MAP_DEBUG)
		e->close("DEBUG");
	mlx_hook(e->win, 17, 0, e->close, "exit");
	return (mlx_loop(e->mlx));
}
