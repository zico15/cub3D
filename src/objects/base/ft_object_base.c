/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:13:41 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/24 20:52:50 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>

void	__destroy_ob(void)
{
	animation().destroy(this());
	printf("DESTROY: %s\n", get_type_str(this()->type));
}

int	check_collision_line(t_vector begin, t_vector end)
{
	int			pixels;
	t_vector	delta;
	t_object	*ob;

	delta.x = end.x - begin.x;
	delta.y = end.y - begin.y;
	pixels = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	delta.x /= pixels;
	delta.y /= pixels;
	delta.w = begin.x;
	delta.h = begin.y;
	while (pixels-- > 0)
	{
		ob = map()->maps_ob[(int) delta.h][(int) delta.w];
		if (ob && ob != this() && ob->type != PLAYER && ob->collision)
			return (0);
		delta.w += delta.x;
		delta.h += delta.y;
	}
	return (1);
}

t_object	*new_object(void)
{
	t_object	*o;

	o = new_object_instance(sizeof(t_object));
	return (o);
}
