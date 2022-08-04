

#include <ft_util.h>

t_sprite	*new_sprite(int w, int h)
{
	t_sprite	*s;

	s = malloc_ob(sizeof(t_sprite));
	s->v.w = w;
	s->v.h = h;
	s->img = image().new(w, h);
	return (s);
}
