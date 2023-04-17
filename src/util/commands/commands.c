/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:50:17 by edos-san          #+#    #+#             */
/*   Updated: 2023/04/17 22:46:10 by edos-san         ###   ########.fr       */
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
	t_object	*ob;

	a = string().trim(data[1]);
	e = hashmap(engine()->clients)->get_key(a);
	ob = fthis()->object;
	free_ob(a);
	if (e)
	{
		fthis()->object = e->value;
		fthis()->object->set_position(vector(atof(data[2]), atof(data[3]), 0, 0));
	}
	fthis()->object = ob;
}

void	send_position(t_player *ob)
{
	static char	t[200];

	t[sprintf(t, "PS :%s:%.5f:%.5f", ob->fd, ob->vector.x, \
	ob->vector.y)] = 0;
	ft_send(engine()->socket, t);
}

void	send_rotation(t_player *ob)
{
	static char	t[200];

	printf("test\n");
	t[sprintf(t, "RT :%s:%.5f:%.5f:%.5f:%.5f", ob->fd, \
	ob->dir.x, ob->dir.y, ob->plane.x, ob->plane.y)] = 0;
	ft_send(engine()->socket, t);
}

void	connect_client(t_player *ob)
{
	static char	t[200];

	printf("test\n");
	t[sprintf(t, "NEW :%s:%.3f:%.3f", ob->fd, ob->vector.x, \
	ob->vector.y)] = 0;
	ft_send(engine()->socket, t);
	ft_send(engine()->socket, t);
}
