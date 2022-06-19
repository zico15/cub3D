/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:29:37 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/19 13:28:17 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

int	main(int argc, char **argv)
{
	//t_engine	*e;
	t_object	*o;
	t_scene		*s;

	(void) argc;
	(void) argv;
	o = new_object();
	s = new_scene(NULL);
	o = (t_object *) s;
	o->update();
	s->update();
	/*e = cread_engine("cub3D", 800, 600);
	e->load_scene(argv[1]);
	mlx_hook(e->win, 17, 0, e->close, "exit");
	return (mlx_loop(e->mlx));*/
}
