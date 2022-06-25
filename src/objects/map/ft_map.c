/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/25 15:49:27 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>

void	*new_map(char *path)
{
	t_map		*map;
	int			fd;
	void		*file;

	map = new_object_instance(sizeof(t_map));
	map->is_map_ok = 1;
	map->map = new_array();
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
	if (!check_maps_nodes(map, map->player))
	{
		map->destroy(map);
		return (NULL);
	}
	else
		cread_map(map);
	return (map);
}
