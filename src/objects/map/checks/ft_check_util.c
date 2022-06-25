/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:49:58 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/25 15:03:27 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_check.h>

void	destroy_node(t_node	*n)
{
	array(n->nodes)->destroy();
	free_ob(n);
}

void	destroy_element_node(t_element	*e)
{
	t_node	*n;
	t_array	*this;

	this = fthis()->array;
	n = e->value;
	if (n)
		destroy_node(n);
	array(this);
	free_ob(e->key);
}
