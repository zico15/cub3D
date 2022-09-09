/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:29:37 by edos-san          #+#    #+#             */
/*   Updated: 2022/09/09 19:59:32 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

void fun(t_element *e, void *v)
{
	(void) v;
	printf("(%i) item: %s\n",e->index, e->value);
}

int	main(int argc, char **argv)
{
	t_engine	*e;
	int			fd;

	void *li;

	li = new_array();
	array(li)->is_value_destroy = 0;
	array(li)->add("D");
	t_element *f = array(li)->add("A");
	array(li)->add("B");
	array(li)->add("C");
	array(li)->remove_index(1);
	array(li)->for_each(fun, NULL);

	//return 0;
	(void) e;
	if (argc < 2)
		printf("ERROR ARG!\n");
	e = cread_engine("cub3D", argv[1], W_WIDTH, W_HEIGHT);
	e->load_maps(argv, argc);
	mlx_hook(e->win, 17, 0, e->close, "exit");
	return (mlx_loop(e->mlx));
}
