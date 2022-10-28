/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu_initial_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/28 19:56:51 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_object_base.h>

void	__mouse_menu(int x, int y, int event)
{
	t_menu		*m;	

	m = (t_menu *) this();
	m->mouse.x = x;
	m->mouse.y = y;
	m->mouse_event = event;
}

void	__effect_sound(int i)
{
	static int	select_err;
	static int	index;

	if (i == index)
		select_err++;
	else
		select_err = 0;
	index = i;
	if (engine()->maps[i])
	{
		select_err = 0;
		index = 0;
		engine()->player_sound("sound/pok.ogg");
		engine()->set_scene(i);
	}
	else
	{
		if (select_err > 2)
		{	
			engine()->player_sound("sound/per.ogg");
			select_err = 0;
		}
		else
			engine()->player_sound("sound/pe.ogg");
	}
}
