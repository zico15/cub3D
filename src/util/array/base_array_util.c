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

	if (!this()->array || !value)
		return (NULL);
	e = malloc_ob(sizeof(t_element));
	if (!e)
		return (NULL);
	e->key = NULL;
	e->value = value;
	e->next = NULL;
	e->destroy = __destroy_element;
	if (!(this()->array)->begin)
		(this()->array)->begin = e;
	else
		(this()->array)->end->next = e;
	(this()->array)->end = e;
	(this()->array)->size++;
	return (e);
}

static void	*base_get_element(int index)
{
	int			i;
	t_element	*e;

	i = 0;
	if (!this()->array || index < 0 || index >= this()->array->size)
		return (NULL);
	e = (this()->array)->begin;
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

	if (!this()->array || !e)
		return ;
	atual = (this()->array)->begin;
	prev = NULL;
	while (atual)
	{
		if (atual == e)
		{
			if ((this()->array)->end == e)
				(this()->array)->end = prev;
			if (prev)
				prev->next = atual->next;
			else
				(this()->array)->begin = atual->next;
			if (e->destroy)
				e->destroy(e);
			(this()->array)->size--;
		}
		prev = atual;
		atual = atual->next;
	}
}

static int	base_destroy(void)
{
	t_element	*b;
	t_element	*temp;

	if (!this()->array)
		return (0);
	b = (this()->array)->begin;
	(this()->array)->begin = NULL;
	this()->array->size = 0;
	while (b)
	{
		temp = b;
		b = b->next;
		if (temp && temp->destroy)
			temp->destroy(temp);
	}
	(this()->array)->end = NULL;
	free_ob(this()->array);
	this()->array = NULL;
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
