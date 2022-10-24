/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:32:18 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/24 13:33:38 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

char	*_str(const char c)
{
	static char	buff[2];

	buff[0] = c;
	return (buff);
}

char	**__copy_list(const char **list)
{
	int		y;
	char	**value;

	if (!list)
		return (NULL);
	value = malloc_ob(sizeof(char *) * \
	(string().size_list((char **) list) + 1));
	y = -1;
	while (list[++y])
		value[y] = string().replace(list[y], " ", "\t");
	value[y] = NULL;
	return (value);
}
