/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_hasmap_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:13:48 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/19 11:33:26 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_string.h>

t_element	*__put_hasmap(char *key, void	*value)
{
	t_element	*v;

	v = hashmap(fthis()->hashmap)->get_key(key);
	if (!v)
		v = array(fthis()->array)->add(value);
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

	e = array(fthis()->array)->get(index);
	if (e)
		return (e);
	return (NULL);
}

t_element	*__get_key_hasmap(char *key)
{
	int			i;
	t_element	*e;

	i = 0;
	if (!fthis()->array)
		return (NULL);
	e = (fthis()->array)->begin;
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
	if (!key || !fthis()->hashmap)
		return ;
	array(fthis()->array)->remove(__get_key_hasmap(key));
}

void	__remove_index_hasmap(int index)
{
	if (index < 0 || !fthis()->hashmap)
		return ;
	array(fthis()->array)->remove_index(index);
}
