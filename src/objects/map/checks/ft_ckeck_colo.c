/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ckeck_colo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:02:48 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/28 17:33:28 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

static void	create_rgb(int r, int g, int b, char c)
{
	if (c == 'C')
		map()->c_color = (r << 16 | g << 8 | b);
	else if (c == 'F')
		map()->f_color = (r << 16 | g << 8 | b);
}

static int	ckeck_numbes(char c, char **v)
{
	int		i;
	char	*tmp;
	int		is_n;
	int		color[3];

	if (string().size_list(v) != 3 && free_list((void **) v))
		return (0);
	i = -1;
	is_n = 1;
	while (++i < 3 && is_n > 0 && v[i])
	{
		tmp = string().trim(v[i]);
		is_n = string().isnumber(tmp);
		if (is_n)
			color[i] = string().atoi(tmp);
		if (color[i] > 255 || color[i] < 0)
			is_n = 0;
		free_ob(tmp);
	}
	free_list((void **) v);
	if (!is_n)
		return (-1);
	else
		create_rgb(color[0], color[1], color[2], c);
	return (1);
}

int	ckeck_color(char *str)
{
	int	i;

	if ((!str || string().size(str) < 7))
		return (0);
	if (*str == 'F' || *str == 'C')
	{
		i = ckeck_numbes(*str, string().split((str + 1), ","));
		if (*str == 'F' && map()->ckeck_file[4] != -1)
			map()->ckeck_file[4] = i;
		else if (*str == 'C' && map()->ckeck_file[5] != -1)
			map()->ckeck_file[5] = i;
	}
	else
		i = 0;
	return (i);
}
