/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:38:15 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/24 12:40:46 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string_util.h>
#include <stdio.h>

char	**__copy_list(const char **list);

static int	ft_size(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_copy(const char *str)
{
	char	*copy;
	int		i;

	if (!str)
		return (NULL);
	i = -1;
	copy = malloc_ob(ft_size(str) + 1);
	while (copy && str[++i])
		copy[i] = str[i];
	copy[i] = 0;
	return (copy);
}

static int	ft_contains(const char *str, const char *hey)
{
	int	i;
	int	j;
	int	co;
	int	p;

	i = -1;
	co = 0;
	p = 0;
	while (str && str[++i] && !co)
	{
		j = 0;
		while (!co && hey && hey[j] && str[i + j] && hey[j] == str[i + j])
		{
			p = i;
			j++;
			if (!hey[j] || !str[i + j])
			{
				co = !hey[j];
				break ;
			}
		}
	}
	return (co + (co * p));
}

static int	__isnumber(const char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

t_string	string(void)
{
	static t_string	str = {
		ft_contains, ft_size, ft_copy, __join, __copy_n, __str_trim,
		__equals, __equals_n, __is_space, __strnstr, __size_list, __replace,
		__isalnum, __split_spacer, __itoa, __atoi, __isnumber, __copy_list
	};

	return (str);
}
