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

static t_element	*base_add_element(void *value)
{
	t_element	*e;

	if (!fthis()->array || !value)
		return (NULL);
	e = malloc_ob(sizeof(t_element));
	if (!e)
		return (NULL);
	e->key = NULL;
	e->value = value;
	e->next = NULL;
	e->destroy = __destroy_element;
	if (!(fthis()->array)->begin)
		(fthis()->array)->begin = e;
	else
		(fthis()->array)->end->next = e;
	(fthis()->array)->end = e;
	(fthis()->array)->size++;
	return (e);
}

static void	*base_get_element(int index)
{
	int			i;
	t_element	*e;

	i = 0;
	if (!fthis()->array || index < 0 || index >= fthis()->array->size)
		return (NULL);
	e = (fthis()->array)->begin;
	while (e)
	{
		if (i == index)
			return (e->value);
		e = e->next;
		i++;
	}
	return (0);
}

static void	base_remove_element(t_element	*e)
{
	t_element	*prev;
	t_element	*atual;

	if (!fthis()->array || !e)
		return ;
	atual = (fthis()->array)->begin;
	prev = NULL;
	while (atual)
	{
		if (atual == e)
		{
			if ((fthis()->array)->end == e)
				(fthis()->array)->end = prev;
			if (prev)
				prev->next = atual->next;
			else
				(fthis()->array)->begin = atual->next;
			if (e->destroy)
				e->destroy(e);
			(fthis()->array)->size--;
		}
		prev = atual;
		atual = atual->next;
	}
}

static int	base_destroy(void)
{
	t_element	*b;
	t_element	*temp;

	if (!fthis()->array)
		return (0);
	b = (fthis()->array)->begin;
	(fthis()->array)->begin = NULL;
	fthis()->array->size = 0;
	while (b)
	{
		temp = b;
		b = b->next;
		if (temp && temp->destroy)
			temp->destroy(temp);
	}
	(fthis()->array)->end = NULL;
	free_ob(fthis()->array);
	fthis()->array = NULL;
	return (1);
}

void	*new_array(void)
{
	t_array	*a;

	a = malloc_ob(sizeof(t_array));
	if (a)
	{
		a->size = 0;
		a->begin = NULL;
		a->end = NULL;
		a->add = base_add_element;
		a->get = base_get_element;
		a->remove = base_remove_element;
		a->destroy = base_destroy;
		a->for_each = __base_for_each;
		a->set = __base_set_element;
		a->remove_index = __base_remove_element_index;
		a->to_str = __to_str;
		array(a);
	}
	return (a);
}
