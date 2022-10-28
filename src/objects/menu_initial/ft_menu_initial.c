/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu_initial.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:14:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/27 17:59:54 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_check.h>
#include <ft_object_base.h>

void	__mouse_menu(int x, int y, int event);

void	__render_select(t_buffer *b, t_menu *m, int i, t_vector v)
{
	if ((m->mouse.y < v.y && (m->mouse.y) > (v.y - 55)) && \
	(m->mouse.x >= v.x && (m->mouse.x) <= (v.w + v.x)))
	{
		if (m->mouse_event)
			printf("map: %i | %i\n", i, (int)m->mouse.w);
		//printf("scene __mouse_menu: %i\n", m->mouse_event);
		b->rectangle(v, 0xff5c0a);
	}
}

static t_vector	render_line(t_buffer *b, char *line, int y)
{
	int			i;
	int			j;
	t_vector	v;

	i = -1;
	j = 1;
	v = vector(100, 100 + (y * 10), 1, 5);
	(void) i;
	(void) j;
	(void) v;
	(void) line;
	b->image_pos(engine()->alfabeto[engine()->maps[y]], \
		v.x, (y * 50) + v.y);
	v.x += 50;
	while (line[++i])
	{
		b->image_pos(engine()->alfabeto[(int) line[i]], \
		v.x + (i * 35), (y * 50) + v.y);
	}
	v.x = 100;
	v.y = ((y * 50) + v.y) + 50;
	v.w += (i * 35) + 70;
	return (v);
}

static	void	__render(t_buffer *b)
{
	int			y;
	t_menu		*m;	

	m = (t_menu *) this();
	b->image_resize(m->background, win()->w, win()->h);
	y = 0;
	while (engine()->args[++y])
	{
		__render_select(b, m, y, \
		render_line(b, engine()->args[y], y));
	}
}

t_object	*new_menu_initial(void)
{
	t_menu	*ob;

	ob = new_object_instance(sizeof(t_menu));
	ob->render = __render;
	if (fthis()->player)
		ob->render = __render;
	ob->background = engine()->load_sprite("imgs/background.xpm");
	ob->funct_mouse = __mouse_menu;
	return ((t_object *) ob);
}
