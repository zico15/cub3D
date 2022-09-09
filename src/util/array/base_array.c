/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 23:15:24 by edos-san          #+#    #+#             */
/*   Updated: 2022/09/09 19:58:16 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_string.h>

void	__base_for_each(void (*fun)(t_element *e, void *v), void *o)
{
	t_element	*temp;
	t_element	*select;
	int			index;
	void		*this_list;

	if (!fthis()->array)
		return ;
	this_list = fthis()->array;
	temp = (fthis()->array)->begin;
	index = 0;
	while (temp)
	{
		select = temp;
		select->index = index++;
		temp = temp->next;
		fun(select, o);
		array(this_list);
	}
}

t_element	*__base_set_element(int index, void *value)
{
	int			i;
	t_element	*e;

	i = 0;
	if (!fthis()->array)
		return (NULL);
	e = (fthis()->array)->begin;
	while (e)
	{
		if (i == index)
		{
			if (e->destroy)
				free_ob(e->value);
			e->value = value;
			return (e);
		}
		e = e->next;
		i++;
	}
	return (0);
}

void	__base_remove_element_index(int index)
{
	t_element	*prev;
	t_element	*atual;
	int			i;

	if (!fthis()->array || index < 0 || index >= fthis()->array->size)
		return ;
	atual = (fthis()->array)->begin;
	prev = NULL;
	i = -1;
	while (atual)
	{
		if (++i == index)
		{
			printf("saad\n");
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

void	**__to_str(void)
{
	t_element	*temp;
	void		**list;
	int			i;

	if (!fthis()->array)
		return (NULL);
	list = malloc_ob(sizeof(void *) * ((fthis()->array)->size + 1));
	if (!list)
		return (NULL);
	i = 0;
	temp = (fthis()->array)->begin;
	while (temp)
	{
		list[i++] = temp->value;
		temp = temp->next;
	}
	list[i] = NULL;
	return (list);
}

void	__destroy_element(t_element	*e)
{
	free_ob(e->key);
	if (fthis()->array->is_value_destroy)
		free_ob(e->value);
	free_ob(e);
}
