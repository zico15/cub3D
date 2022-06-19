/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 00:06:50 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/19 02:51:06 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

t_this	*this(void)
{
	static t_this	t;

	return (&t);
}

t_array	*array(t_array *a)
{
	this()->array = a;
	return (a);
}

t_engine	*engine(void)
{
	return (this()->engine);
}
