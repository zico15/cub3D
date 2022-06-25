/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:15:49 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/25 14:24:18 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <stdlib.h>

int	free_ob(void *v)
{
	if (v == NULL)
		return (1);
	free(v);
	return (1);
}

int	free_list(char **str)
{
	int		i;

	if (str)
	{
		i = -1;
		while (str[++i])
			free_ob(str[i]);
		free_ob(str);
		return (i);
	}
	return (0);
}

void	*malloc_ob(size_t __size)
{
	void			*v;
	unsigned char	*temp;

	if (__size < 1)
		return (NULL);
	v = malloc(__size);
	if (!v)
		engine()->close("Error");
	temp = (unsigned char *) v;
	while (__size-- > 0)
		*(temp++) = (unsigned char) 0;
	return (v);
}
