/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_mash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:37:26 by ezequeil          #+#    #+#             */
/*   Updated: 2022/10/27 13:37:57 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_nav_mesh.h>

void	__free_nav_mash_list(void);

t_nav_node	*cread_node(t_nav_mesh *agent, int x, int y)
{
	t_nav_node		*n;

	n = malloc_ob(sizeof(t_nav_node));
	n->x = x;
	n->y = y;
	array(agent->memory)->add(n);
	return (n);
}

static void	__clear_date(void)
{
	t_nav_mesh	*agent;

	agent = fthis()->agent;
	array(agent->path)->remove_all();
	array(agent->open)->remove_all();
	array(agent->close)->remove_all();
	array(agent->memory)->remove_all();
	agent->begin = NULL;
}

static void	*__set_destination(t_vector start, t_vector dest)
{
	t_nav_mesh	*agent;

	agent = fthis()->agent;
	__clear_date();
	if (start.x == dest.x && start.y == dest.y)
		return (NULL);
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
	agent->memory = new_array();
	agent->path = new_array();
	agent->open = new_array();
	array(agent->open)->is_value_destroy = 0;
	agent->close = new_array();
	array(agent->close)->is_value_destroy = 0;
	return (agent);
}
