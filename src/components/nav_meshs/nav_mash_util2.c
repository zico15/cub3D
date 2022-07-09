/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_mash_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:37:26 by ezequeil          #+#    #+#             */
/*   Updated: 2022/07/08 21:03:36 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_nav_mesh.h>

int	__expand(t_nav_mesh *agent, t_nav_node *n)
{
	int	size_w;
	int	size_h;

	size_w = map()->vector.w / GRID_SIZE;
	size_h = map()->vector.h / GRID_SIZE;
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
		v->x = start->x * GRID_SIZE;
		v->y = start->y * GRID_SIZE;
		array(agent->rota)->add(v);
		start = start->next;
	}
}

static t_nav_node	*check_pathfinding(t_nav_mesh *agent, t_element *e, \
t_nav_node *node)
{
	t_element	*select_e;
	t_nav_node	*temp;

	while (e)
	{
		temp = (t_nav_node *) e->value;
		if (!node)
		{
			select_e = e;
			node = temp;
		}
		if (temp->f < node->f)
		{
			node = temp;
			select_e = e;
		}
		e = e->next;
	}
	if (!node)
		return (NULL);
	select_e->value = NULL;
	array(agent->open)->remove(select_e);
	return (node);
}

void	__pathfinding(t_nav_mesh	*agent, t_nav_node	*node)
{
	if (!array(agent->open)->size)
		return ;
	node = check_pathfinding(agent, array(agent->open)->begin, node);
	if (!node)
		return ;
	array(agent->close)->add(node);
	if (__expand(agent, node))
		create_rota(agent, node);
	else if (array(agent->open)->size > 0)
		__pathfinding(agent, NULL);
}
