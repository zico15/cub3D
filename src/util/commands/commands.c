/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:50:17 by edos-san          #+#    #+#             */
/*   Updated: 2023/04/17 21:09:02 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_socket.h>
#include <ft_util.h>
#include <stdio.h>

void	new_client(const char **data)
{
	(scene())->add_client(string().trim(data[1]), atof(data[2]), \
	atof(data[3]));
}


void	set_client_position(const char **data)
{
	char		*a;
	t_element	*e;
	t_player	*p;

	a = string().trim(data[1]);
	e = hashmap(engine()->clients)->get_key(a);
	free_ob(a);
	if (e)
	{
		p = e->value;
		p->vector.x = atof(data[2]);
		p->vector.y = atof(data[3]);
	}	
}

void	send_position(t_player *ob)
{
	static char	t[200];

	t[sprintf(t, "PS :%s:%.3f:%.3f", ob->fd, ob->vector.x, \
	ob->vector.y)] = 0;
	ft_send(engine()->socket, t);
}

void	send_rotation(t_player *ob)
{
	static char	t[200];

	printf("test\n");
	t[sprintf(t, "RT :%s:%.3f:%.3f:%.3f:%.3f", ob->fd, \
	ob->dir.x, ob->dir.y, ob->plane.x, ob->plane.y)] = 0;
	ft_send(engine()->socket, t);
}

