/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_hasmap_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:13:48 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/19 01:14:23 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_string.h>

t_element	*__put_hasmap(char *key, void	*value)
{
	t_element	*v;

	v = hashmap(this()->hashmap)->get_key(key);
	if (!v)
		v = array(this()->array)->add(value);
	else
	{
		free_ob(v->key);
		v->key = key;
		v->value = value;
	}
	if (!v)
		return (0);
	v->key = key;
	return (v);
}

t_element	*__get_index_hasmap(int index)
{
	t_element	*e;

	e = array(this()->array)->get(index);
	if (e)
		return (e);
	return (NULL);
}

t_element	*__get_key_hasmap(char *key)
{
	int			i;
	t_element	*e;

	i = 0;
	if (!this()->array)
		return (NULL);
	e = (this()->array)->begin;
	while (e)
	{
		if (string().equals(key, e->key))
			return (e);
		e = e->next;
		i++;
	}
	return (NULL);
}

void	__remove_element_hasmap(char	*key)
{
	if (!key || !this()->hashmap)
		return ;
	array(this()->array)->remove(__get_key_hasmap(key));
}

void	__remove_index_hasmap(int index)
{
	if (index < 0 || !this()->hashmap)
		return ;
	array(this()->array)->remove_index(index);
}
