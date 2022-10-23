/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:39:12 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/14 18:19:37 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

void	__destroy_animation(t_object *ob);

static void	__update_animation(t_object *ob, int animation)
{
	int	i;

	i = animation;
	if (!ob->animation)
		return ;
	if (ob->animation[i].is_run && (ob->animation[i].time < now()))
	{
		if (++ob->animation[i].index >= ob->animation[i].size)
		{
			ob->animation[i].index = 0;
			ob->animation[i].is_run = ob->animation[i].is_repeat;
		}
		ob->animation[i].time = now() + ob->animation[i].time_delay;
		ob->sprite = ob->animation[i].list[ob->animation[i].index];
	}
}

static void	__update_animation_all(t_object *ob)
{
	int	i;

	i = -1;
	while (++i < ob->size_animation)
		__update_animation(ob, i);
}

static t_animation	*__create_animation(t_object *ob, int size)
{
	t_animation	*animation;

	animation = malloc_ob(sizeof(t_animation) * (size + 1));
	ob->size_animation = size;
	return (animation);
}

static void	__load_animation(char *file, int size, t_animation \
*animations, double velocity)
{
	static int			i = 0;
	int					k[2];

	i = -1;
	k[0] = -1;
	file = string().copy(file);
	while (file[++i])
	{
		if (k[0] == -1 && string().isnumber(_str(file[i])))
			k[0] = i;
		else if (string().isnumber(_str(file[i])))
			k[1] = i;
	}
	i = -1;
	animations->list = malloc_ob(sizeof(t_sprite *) * size);
	animations->size = size;
	animations->time_delay = velocity;
	while (++i < size)
	{
		file[k[0]] = (i / 10) + '0';
		file[k[1]] = (i % 10) + '0';
		animations->list[i] = engine()->load_sprite(file);
	}
	free_ob(file);
}

t_fanimation	animation(void)
{
	static t_fanimation	a = {
		__create_animation, __load_animation, __update_animation_all,
		__update_animation, __destroy_animation
	};

	return (a);
}
