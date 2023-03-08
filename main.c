/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:29:37 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/01 16:43:11 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

int	main(int argc, char **argv)
{
	t_engine	*e;

	if (argc < 2 || argc >= 50)
	{
		printf("ERROR ARG!\n");
		return (1);
	}
	e = cread_engine("cub3D");
	e->load_maps(argv, argc);
	mlx_hook(e->win, 17, 0, e->close, "exit");
	return (mlx_loop(e->mlx));
}