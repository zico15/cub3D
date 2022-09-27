/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/09/18 20:07:17 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_check.h>

int	check_map_color(char *map_color)
{
	char	*clean_str;
	char	**rgb_val;
	char	*tmp;
	int		pos;

	if (!map_color)
		return (0);
	if (string().contains(map_color, "C"))
		clean_str = string().replace(map_color, "", "C");
	else
		clean_str = string().replace(map_color, "", "F");
	tmp = clean_str;
	clean_str = string().trim(clean_str);
	free(tmp);
	rgb_val = string().split(clean_str, ",");
	pos = 0;
	while(rgb_val && rgb_val[pos])
	{
		if (!string().isnumber(rgb_val[pos])
			|| string().atoi(rgb_val[pos]) > 255
			|| string().atoi(rgb_val[pos]) < 0)
			return (0);
		pos++;
	}
	free(clean_str);
	free_list(rgb_val);
	return (1);
}

int upload_map_color(char *map_color)
{
	char			*clean_str;
	char			**rgb_val;
	char			*tmp;
	int	color;

	if (!map_color)
		return (0);
	if (string().contains(map_color, "C"))
		clean_str = string().replace(map_color, "", "C");
	else
		clean_str = string().replace(map_color, "", "F");
	tmp = clean_str;
	clean_str = string().trim(clean_str);
	free(tmp);
	rgb_val = string().split(clean_str, ",");
	color = (string().atoi(rgb_val[0]) << 16)
			+ (string().atoi(rgb_val[1]) << 8)
			+ string().atoi(rgb_val[2]);
	free(clean_str);
	free_list(rgb_val);
	return (color);
}

static void	__load_map(char *path)
{
	int			fd;
	void		*file;
	t_map		*map;

	map = (t_map *) this();
	fd = open(path, O_RDONLY);
	if (fd == -1)
		engine()->close("Error");
	file = new_array();
	while (array(file)->add(get_next_line(fd)))
		;
	if (file)
		(array(file))->for_each(check_color, map);
	check_map(map, -1, -1);
	array(file)->destroy();
	add_object_all_map(map);
	if (!check_maps_nodes(map, map->player)
		|| !check_map_color(map->c) || !check_map_color(map->f))
		printf("load map: %s (ERROR)\n", path);
	else
		printf("load map: %s\n", path);
	map->size_width = (int) map->vector.w / GRID_SIZE;
	map->size_height = (int) map->vector.h / GRID_SIZE;
	map->c_color = upload_map_color(map->c);
	map->f_color = upload_map_color(map->f);
	cread_map(map);
}

t_map	*new_map(void)
{
	t_map		*map;

	map = new_object_instance(sizeof(t_map));
	map->is_map_ok = 1;
	map->type = MAP;
	map->map = new_array();
	map->load = __load_map;
	fthis()->map = map;
	return (map);
}
