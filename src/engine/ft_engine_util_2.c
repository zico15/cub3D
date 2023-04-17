/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine_util_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:01 by edos-san          #+#    #+#             */
/*   Updated: 2023/04/17 21:44:47 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

static t_object	*new_object_null(void)
{
	return (NULL);
}

/*
	cvlc
	nvlc
	vlc, qvlc, svlc, nvlc, rvlc, cvlc
*/
static void	__player_soud(char *file)
{
	char	*cmd;

	if (!file)
		return ;
	cmd = string().join("paplay ", file);
	if (!fork())
	{
		system(cmd);
		exit(0);
	}
	free_ob(cmd);
}

void	init_list_objects_functions(void)
{
	int		w;
	int		h;

	engine()->player_sound = __player_soud;
	mlx_get_screen_size(engine()->mlx, &w, \
	&h);
	engine()->v.w = 1080;
	engine()->v.h = 800;
	engine()->width = engine()->v.w;
	engine()->height = engine()->v.h;
	engine()->is_game = 0;
	engine()->new_obs['0'] = new_object_null;
	engine()->new_obs['1'] = new_portal;
	engine()->new_obs['I'] = new_enemy;
	engine()->new_obs['K'] = new_kit;
	engine()->new_obs['D'] = new_door;
	engine()->new_obs['N'] = (void *) new_player;
	engine()->new_obs['S'] = (void *) new_player;
	engine()->new_obs['W'] = (void *) new_player;
	engine()->new_obs['E'] = (void *) new_player;
	engine()->new_obs['T'] = new_barrel;
	engine()->new_obs['P'] = new_portal;
}

t_sprite	*__new_sprite(int w, int h)
{
	t_sprite	*s;

	s = malloc_ob(sizeof(*s));
	s->img = image().new(w, h);
	s->v.w = w;
	s->v.h = h;
	s->data.img = s->img;
	s->data.addr = mlx_get_data_addr(s->data.img, &s->data.bits_per_pixel, \
	&s->data.line_length, &s->data.endian);
	return (s);
}


void	_commads(char *data)
{
	t_player		*p;
	const char		**datas;

	if (!scene() || !scene()->player)
		return ;
	p = scene()->player;
	write(2, data, string().size(data));
	datas = (void *) string().split(data, ":");
	if (data[0] == 'F')
	{	
		p->fd = string().trim(datas[1]);
		//send_position(p);
		//send_rotation(p);
		connect_client(p);

	}
	else if (data[0] == 'N')
		new_client(datas);
	else if (data[0] == 'P')
		set_client_position(datas);
	free_list((void **) datas);
}
