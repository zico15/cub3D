/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:51:06 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/20 13:51:06 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_base_array.h>
#include <ft_base_array_util.h>
#include <ft_util.h>

void	__base_remove_element_value(void *value)
{
	t_element	*prev;
	t_element	*atual;

	if (!fthis()->array || !value)
		return ;
	atual = (fthis()->array)->begin;
	prev = NULL;
	while (atual)
	{
		if (atual->value == value)
		{
			if ((fthis()->array)->end == atual)
				(fthis()->array)->end = prev;
			if (prev)
				prev->next = atual->next;
			else
				(fthis()->array)->begin = atual->next;
			if (atual->destroy)
				atual->destroy(atual);
			(fthis()->array)->size--;
			break ;
		}
		prev = atual;
		atual = atual->next;
	}
}
