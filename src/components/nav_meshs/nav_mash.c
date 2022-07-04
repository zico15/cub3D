/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_mash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:37:26 by ezequeil          #+#    #+#             */
/*   Updated: 2022/07/04 20:14:25 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_nav_mesh.h>

static int	expand(t_nav_mesh *agent, t_nav_node *n)
{
	int	size_w;
	int	size_h;

	size_w = agent->map->vector.w / 32;
	size_h = agent->map->vector.h / 32;
	if (!agent)
		return (0);
	if (check_case_node(agent, vector(n->x, n->y + 1, size_w, size_h), 10))
		create_nav_node(agent, n, vector(n->x, n->y + 1, 10, 0));
	if (check_case_node(agent, vector(n->x + 1, n->y, size_w, size_h), 10))
		create_nav_node(agent, n, vector(n->x + 1, n->y, 10, 0));
	if (check_case_node(agent, vector(n->x, n->y - 1, size_w, size_h), 10))
		create_nav_node(agent, n, vector(n->x, n->y - 1, 10, 0));
	if (check_case_node(agent, vector(n->x - 1, n->y, size_w, size_h), 10))
		create_nav_node(agent, n, vector(n->x - 1, n->y, 10, 0));
	return ((n->x == (agent->dest).x && n->y == (agent->dest).y));
}

static void	create_rota(t_nav_mesh	*agent, t_nav_node *node)
{
	t_nav_node	*start;
	t_nav_node	*next;
	t_vector	*v;

	start = node;
	next = NULL;
	if (start)
		agent->rota = new_array();
	while (start)
	{
		start->next = next;
		next = start;
		if (!start->previu)
			break ;
		start = start->previu;
	}
	while (start)
	{
		v = malloc_ob(sizeof(t_vector));
		v->x = start->x * 32;
		v->y = start->y * 32;
		array(agent->rota)->add(v);
		start = start->next;
	}
}

static void	pathfinding(t_nav_mesh	*agent, t_nav_node	*node)
{
	t_nav_node	*temp;
	t_element	*e;
	t_element	*select;

	if (!array(agent->open)->size)
		return ;
	e = array(agent->open)->begin;
	while (e)
	{
		temp = (t_nav_node *) e->value;
		if (!node)
		{
			select = e;
			node = temp;
		}
		if (temp->f < node->f)
		{
			node = temp;
			select = e;
		}
		e = e->next;
	}
	if (!node)
		return ;
	select->value = NULL;
	array(agent->open)->remove(select);
	array(agent->close)->add(node);
	if (expand(agent, node))
		create_rota(agent, node);
	else if (array(agent->open)->size > 0)
		pathfinding(agent, NULL);
}

static void	*__set_destination(t_map *map, t_vector start, t_vector dest)
{
	t_nav_mesh	*agent;

	agent = fthis()->agent;
	if (agent->rota)
	{
		array((agent)->rota)->destroy();
		agent->rota = NULL;
	}
	dest.x /= 32;
	dest.y /= 32;
	agent->open = new_array();
	agent->close = new_array();
	agent->start = start;
	agent->dest = dest;
	agent->map = map;
	agent->start.x /= 32;
	agent->start.y /= 32;
	agent->start.h = 1;
	agent->begin = create_nav_node(agent, NULL, agent->start);
	expand(agent, agent->begin);
	if (agent && agent->open && agent->close)
		pathfinding(agent, NULL);
	free_nav_mash_list(agent);
	return (agent->rota);
}

t_nav_mesh	*new_nav_mesh(void)
{
	t_nav_mesh	*agent;

	agent = malloc_ob(sizeof(t_nav_mesh));
	agent->set_destination = __set_destination;
	return (agent);
}
