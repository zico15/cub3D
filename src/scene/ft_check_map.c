/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:03:31 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/21 22:28:37 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <pthread.h>

static int	check_case(t_scene *scene, t_vector v, t_node *n)
{
	(void) n;
	if ((v.x >= 0 && v.x < v.w) && (v.y >= 0 && v.y < v.h) && \
	scene->maps[v.y][v.x] != '1' && !scene->check[v.y][v.x])
	{
		if (scene->maps[v.y][v.x] == ' ')
		{
			scene->check[v.y][v.x] = 0;
			printf("ERRR\n");
			return (0);
		}
		scene->check[v.y][v.x] = 1;
		return (1);
	}
	return (0);
}

static t_node	*create_node(int x, int y, int v)
{
	t_node	*n;
	t_array	*this;

	this = fthis()->array;
	n = malloc_ob(sizeof(t_node));
	n->x = x;
	n->y = y;
	n->v = v;
	n->nodes = new_array();
	array(this);
	return (n);
}

static void	expand(t_scene *scene, t_node *n, int size_w, int size_h)
{
	if (!n)
		return ;
	// baixo
	if (check_case(scene, vector(n->x, n->y + 1, size_w, size_h), n))
		(array(n->nodes))->add(create_node(n->x, n->y + 1, n->v + 1));
	// direita
	if (check_case(scene, vector(n->x + 1, n->y, size_w, size_h), n))
		(array(n->nodes))->add(create_node(n->x + 1, n->y, n->v + 1));
	// cima
	if (check_case(scene, vector(n->x, n->y - 1, size_w, size_h), n))
		(array(n->nodes))->add(create_node(n->x, n->y - 1, n->v + 1));
	// esquerda
	if (check_case(scene, vector(n->x - 1, n->y, size_w, size_h), n))
		(array(n->nodes))->add(create_node(n->x - 1, n->y, n->v + 1));
}

void	*satrt_nodes_checks(void *o)
{
	int			i;
	t_array		*this;
	t_scene		*scene;
	t_node		*n;

	n = (t_node *) o;
	scene = fthis()->scene;
	if (!scene || !n)
		return (NULL);
	expand(scene, n, scene->vector.w / 32, scene->vector.h / 32);
	usleep(100000);
	this = fthis()->array;
	if (array(n->nodes)->size)
	{
		i = -1;
		while (++i < array(n->nodes)->size)
		{
			satrt_nodes_checks(array(n->nodes)->get(i));
			array(this);
		}
		return (o);
	}
	return (NULL);
}

int	check_maps_nodes(t_scene *scene, t_vector start)
{
	t_node		*n;
	pthread_t	p;

	n = create_node(start.x, start.y, 0);
	check_case(scene, vector(n->x, n->y, scene->vector.w / 32, \
	scene->vector.h / 32), n);
	pthread_create(&p, NULL, satrt_nodes_checks, n);
	return (1);
}
