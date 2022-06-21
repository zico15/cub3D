/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:29:37 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/20 22:20:36 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

int	main(int argc, char **argv)
{
	t_engine	*e;

	(void) argc;
	(void) argv;
	printf("PID: %i\n", getpid());
	e = cread_engine("cub3D", argv[1], 0, 0);
	mlx_hook(e->win, 17, 0, e->close, "exit");
	return (mlx_loop(e->mlx));
}
