/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/28 15:27:27 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_check.h>

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
	if (!check_maps_nodes(map, map->player))
		printf("load map: %s (ERROR)\n", path);
	else
		printf("load map: %s\n", path);
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
