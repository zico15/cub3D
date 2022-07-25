/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_teste.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/09 20:01:29 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_object_base.h>

static int	get_color(t_map *m, t_vector v)
{
	int	x;
	int	y;

	x = v.x;
	y = v.y;
	if (m->maps[y][x] == '1')
		return (0x00FF0000);
	if (m->maps[y][x] == '0' || m->maps[y][x] == '2')
		return (0x000000FF);
	if (m->maps[y][x] == 'N')
		return (0x0000FF00);
	if (m->maps[y][x] == 'D')
		return (0x00CC9900);
	return (0x0);
}

static void	__reander(void)
{
	int 		x;
	t_vector	v;

	v = map()->vector;
	v.w = (v.w / GRID_SIZE);
	v.h = (v.h / GRID_SIZE);
	while (v.y < v.h && v.y < 10)
	{
		v.x = 0;
		while (v.x < v.w && v.x < 10)
		{
			(render()).pixel_put_rec(this()->img, get_color(map(), v), \
			vector(v.x * 20, v.y * 25, 20, 25));
			v.x++;
		}
		v.y++;
	}
	render().print_ob(this());
}



t_object	*new_menu(void)
{
	t_object	*ob;

	ob = new_object_instance(sizeof(t_object));
	ob->render = __reander;
	ob->vector.w = 200;
	ob->vector.h = 150;
	ob->img = mlx_new_image(engine()->mlx, ob->vector.w , \
	ob->vector.h);
	render().pixel_put_rec(ob->img, 0x0000FFFF,ob->vector);
	ob->vector.x = engine()->width - ob->vector.w;
	ob->vector.y = 0;//engine()->height - ob->vector.h;
	return (ob);
}
