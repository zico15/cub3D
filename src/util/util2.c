/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:01:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/25 20:43:40 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <stdio.h>

void	print_list(char **list)
{
	int	i;

	i = 0;
	if (!list)
		return ;
	while (list[i])
		printf("%s", list[i++]);
}

void	__destroy_element_scene(t_element	*e)
{
	t_scene		*s;
	t_object	*temp;

	s = (t_scene *) e->value;
	temp = fthis()->object;
	fthis()->scene = s;
	fthis()->map = s->map;
	fthis()->player = s->player;
	fthis()->camera = s->camera;
	if (s && s->destroy)
		s->destroy();
	free_ob(e->key);
	free_ob(e->value);
	free_ob(e);
	fthis()->object = temp;
}

void	__destroy_element_object(t_element	*e)
{
	t_object	*ob;
	void		*list;
	t_object	*temp;

	ob = (t_object *) e->value;
	temp = fthis()->object;
	list = fthis()->array;
	fthis()->object = ob;
	if (ob && ob->destroy)
		ob->destroy();
	free_ob(e->key);
	free_ob(e->value);
	free_ob(e);
	fthis()->object = temp;
	fthis()->array = list;
}

/*
# define WIDTH 1080
# define HEIGHT 860
*/
t_vector	*win(void)
{
	return (&engine()->v);
}
