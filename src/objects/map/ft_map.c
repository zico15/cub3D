/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/13 17:05:28 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>
#include <ft_check.h>

void		__destroy_ob_map(void);
void		__render_map(t_buffer	*b);
int			check_path(char *path);
int			ckeck_all(void *file);
int			check_maps_nodes(t_map *map, char **temp, int x, int y);
int			check_maps_portal(t_map *map, char **temp, int x, int y);
void 		copy_map_portal(t_map *map, char **temp);

void		cread_mini_map(t_map *m);
t_object	*__get_object_map(int x, int y);

static void	__funct_key(char *key, int event)
{
	if (event == EVENT_CLICK && key[KEY_M])
		engine()->set_scene(0);
}

static void	__load_map(char *path)
{
	t_map		*map;
	char		**temp;

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
		temp = (char **) array(map->file)->to_str();
		if (check_maps_nodes(map, temp, -1, -1))
		{	
			add_object_all_map(map);
			system("clear");
			//copy_map_portal(map, map->maps);
			check_maps_portal(map, map->maps, map->player.x, map->player.y);
		}
		free_ob(temp);
	}
	engine()->maps[++engine()->size_maps] = map->is_map_ok;
	array(map->file)->destroy();
	printf("load_maps: %i\n", map->is_map_ok);
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
