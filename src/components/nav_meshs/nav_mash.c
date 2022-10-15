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

void	__free_nav_mash_list();

static void	__clear_date()
{
	t_nav_mesh	*agent;

	agent = fthis()->agent;
	if (agent->path)		
		array((agent)->path)->destroy();
	if (agent->open)
		array(agent->open)->destroy();
	if (agent->close)
		array(agent->close)->destroy();
	free_ob(agent->begin);
	agent->open = NULL;
	agent->close = NULL;
	agent->path = NULL;
	agent->begin = NULL;
}

static void	*__set_destination(t_vector start, t_vector dest)
{
	t_nav_mesh	*agent;
	void		*list;

	agent = fthis()->agent;
	__clear_date();
	if (start.x == dest.x && start.y == dest.y)
		return;
	agent->open = new_array();
	agent->close = new_array();
	agent->start = start;
	agent->dest = dest;
	agent->start.h = 1;
	agent->begin = create_nav_node(agent, NULL, agent->start);
	__expand(agent, agent->begin);

	if (agent && agent->open && agent->close)
		__pathfinding(agent, NULL);
	return (agent->path);
}

t_nav_mesh	*new_nav_mesh(void)
{
	t_nav_mesh	*agent;

	agent = malloc_ob(sizeof(t_nav_mesh));
	agent->set_destination = __set_destination;
	agent->clear = __clear_date;
	agent->destroy = __free_nav_mash_list;
	return (agent);
}
