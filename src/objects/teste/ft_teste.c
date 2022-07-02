/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_teste.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/02 00:09:42 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>

static void	__funct_key(int key, int type_event)
{
	(void) key;
	(void) type_event;
	if (key != 65293)
		return ;
	printf("teste: %i\n", key);
}


void	*new_teste(void)
{
	t_object	*ob;
	
	ob = new_object_instance(sizeof(t_object));
	ob->funct_key = __funct_key;
	return (ob);
}
