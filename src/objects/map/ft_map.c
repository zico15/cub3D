/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/07 22:54:33 by ezequeil         ###   ########.fr       */
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
	printf("load map: %s\n", path);
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
	if (!check_maps_nodes(map, map->player)) // not checking because player is NULL
		printf("ERROR MAP\n");
	cread_map(map);
}

static void	__update(void)
{
	render().print_ob(this());
}

t_map	*new_map(void)
{
	t_map		*map;

	map = new_object_instance(sizeof(t_map));
	map->is_map_ok = 1;
	map->update = __update;
	map->type = MAP;
	map->map = new_array();
	map->load = __load_map;
	fthis()->map = map;
	return (map);
}
