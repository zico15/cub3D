/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ckeck_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:02:48 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/27 17:18:09 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

int			ckeck_color(char *str);
static int	check_path_image(char *path);

static int	check_date(void)
{
	int	i;

	i = map()->ckeck_file[0];
	i += map()->ckeck_file[1];
	i += map()->ckeck_file[2];
	i += map()->ckeck_file[3];
	i += map()->ckeck_file[4];
	i += map()->ckeck_file[5];
	return (i == 6);
}

int	ckeck_all(void *file)
{
	char	*line;
	int		is;
	int		count;

	is = 1;
	if (array(file)->size == 0)
		return (0);
	while (array(file)->size && is && !check_date())
	{
		line = array(file)->get(0);
		if (string().size(line) > 0)
			line = string().trim(line);
		if (string().size(line) > 0)
		{
			count = 0;
			count += ckeck_color(line);
			count += check_path_image(line);
			if (!count)
				is = 0;
		}
		free_ob(line);
		array(file)->remove_index(0);
	}
	return (is);
}

int	check_path(char *path)
{
	int	fd;
	int	size;

	size = string().size(path);
	if (!path || size < 4 || !(string()).equals((path + (size - 4)), ".cub"))
		return (-1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (fd);
	return (fd);
}

static int	load_sprits_wall(char *path, int i)
{
	int	fd;

	path = string().trim(path);
	fd = open(path, O_RDONLY);
	if (fd >= 0)
	{
		close(fd);
		map()->sprits_wall[i] = engine()->load_sprite(path);
		map()->ckeck_file[i] = 1;
	}
	free_ob(path);
	return (fd >= 0);
}

static int	check_path_image(char *path)
{
	int	size;

	size = string().size(path);
	if (!path || size < 4 || !(string()).equals((path + (size - 4)), ".xpm"))
		return (0);
	if (string().equals_n(path, "NO ", 3))
		return (load_sprits_wall((path + 3), 0));
	if (string().equals_n(path, "SO ", 3))
		return (load_sprits_wall((path + 3), 1));
	if (string().equals_n(path, "WE ", 3))
		return (load_sprits_wall((path + 3), 2));
	if (string().equals_n(path, "EA ", 3))
		return (load_sprits_wall((path + 3), 3));
	return (0);
}
