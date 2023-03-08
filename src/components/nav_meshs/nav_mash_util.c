/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_mash_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:37:26 by ezequeil          #+#    #+#             */
/*   Updated: 2023/03/06 20:32:33 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_nav_mesh.h>

t_nav_node	*cread_node(t_nav_mesh *agent, int x, int y);

static int	check_case_node_free(t_nav_mesh *agent, int x, int y)
{
	t_element	*e;
	t_node		*n;

	if (!array(agent->close)->size)
		return (1);
	e = array(agent->close)->begin;
	while (e)
	{
		n = (t_node *) e->value;
		if (x == n->x && y == n->y)
			return (0);
		e = e->next;
	}
	if (!array(agent->open)->size)
		return (1);
	e = array(agent->open)->begin;
	while (e)
	{
		n = (t_node *) e->value;
		if (x == n->x && y == n->y)
			return (0);
		e = e->next;
	}
	return (1);
}

int	check_case_node(t_nav_mesh *agent, t_vector v)
{
	static t_object	*ob;

	if ((v.x >= 0.0 && v.x < v.w) && (v.y >= 0.0 && v.y < v.h))
		ob = map()->maps_ob[(int)v.y][(int)v.x];
	return ((!ob || (ob != agent->ob && !ob->collision)) && \
		check_case_node_free(agent, v.x, v.y));
}

static double	cal_cust(t_vector start, t_vector dest)
{
	double	x;
	double	y;
	double	d;

	x = (start.x - dest.x);
	x *= ((x > 0) - (x < 0));
	y = (start.y - dest.y);
	y *= ((y > 0) - (y < 0));
	d = 0;
	if (x && y)
	{
		if (x < y)
			d += (x * 14) + ((y - x) * 10);
		else
			d += (y * 14) + ((x - y) * 10);
	}
	else
		d = (x * 10) + (y * 10);
	return (d);
}

void	__free_nav_mash_list(void)
{
	t_nav_mesh	*agent;

	agent = fthis()->agent;
	if (!agent)
		return ;
	array(agent->path)->destroy();
	array(agent->close)->destroy();
	array(agent->open)->destroy();
	array(agent->memory)->destroy();
	free_ob(agent);
	fthis()->agent = NULL;
}

t_nav_node	*create_nav_node(t_nav_mesh *agent, t_nav_node *previu, t_vector v)
{
	t_nav_node		*n;

	n = cread_node(agent, v.x, v.y);
	if (previu)
		previu->next = n;
	n->previu = previu;
	n->g = v.w;
	if (previu)
		n->g += previu->g;
	n->h = cal_cust(vector(n->x, n->y, 0, 0), agent->dest);
	n->f = n->g + n->h;
	if (!v.h)
		(array(agent->open))->add(n);
	return (n);
}
