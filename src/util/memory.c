/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:15:49 by edos-san          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/19 11:17:15 by edos-san         ###   ########.fr       */
=======
/*   Updated: 2022/06/19 02:37:11 by edos-san         ###   ########.fr       */
>>>>>>> ezequiel
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
	void	*v;

	if (__size < 1)
		return (NULL);
	v = malloc(__size);
	if (!v)
		engine()->close("Error");
	return (v);
}
