/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/23 21:08:39 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_check.h>

void		__destroy_ob_map(void);
void		__render_map(t_buffer	*b);
int			check_path(char *path);
int			ckeck_all(void *file);
int			check_maps_nodes(t_map *map, int x, int y);

void		cread_mini_map(t_map *m);
t_object	*__get_object_map(int x, int y);

static void	__funct_key(int *key, int event)
{
	if (event == EVENT_CLICK && key[KEY_M])
		map()->is_print = !map()->is_print;
}

static void	__load_map(char *path)
{
	t_map		*map;

	map = (t_map *) this();
	map->is_map_ok = check_path(path);
	if (!map->is_map_ok)
		return ;
	map->file = new_array();
	while (array(map->file)->add(get_next_line(map->is_map_ok)))
		;
	close(map->is_map_ok);
	map->is_map_ok = ckeck_all(map->file);
	if (map->is_map_ok)
	{
		map->maps = (char **) array(map->file)->to_str();
		if (check_maps_nodes(map, -1, -1))
		{
			printf("MAP: add_object_all_map\n");
			add_object_all_map(map);
		}
	}
}

t_object	*new_map(void)
{
	t_map		*map;

	map = new_object_instance(sizeof(t_map));
	map->is_map_ok = 1;
	map->is_print = 0;
	map->type = MAP;
	map->render = __render_map;
	map->destroy = __destroy_ob_map;
	map->load = __load_map;
	map->funct_key = __funct_key;
	map->get_object = __get_object_map;
	fthis()->map = map;
	return ((t_object *) map);
}
