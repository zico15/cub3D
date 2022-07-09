/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_mash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:37:26 by ezequeil          #+#    #+#             */
/*   Updated: 2022/07/08 21:04:23 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_nav_mesh.h>

static void	*__set_destination(t_vector start, t_vector dest)
{
	t_nav_mesh	*agent;

	agent = fthis()->agent;
	if (agent->rota)
	{
		array((agent)->rota)->destroy();
		agent->rota = NULL;
	}
	dest.x /= GRID_SIZE;
	dest.y /= GRID_SIZE;
	agent->open = new_array();
	agent->close = new_array();
	agent->start = start;
	agent->dest = dest;
	agent->start.x /= GRID_SIZE;
	agent->start.y /= GRID_SIZE;
	agent->start.h = 1;
	agent->begin = create_nav_node(agent, NULL, agent->start);
	__expand(agent, agent->begin);
	if (agent && agent->open && agent->close)
		__pathfinding(agent, NULL);
	free_nav_mash_list(agent);
	return (agent->rota);
}

t_nav_mesh	*nav_mesh(t_nav_mesh	*agent)
{
	fthis()->agent = agent;
	return (agent);
}

t_nav_mesh	*new_nav_mesh(void)
{
	t_nav_mesh	*agent;

	agent = malloc_ob(sizeof(t_nav_mesh));
	agent->set_destination = __set_destination;
	return (agent);
}
