/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:13:41 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/25 14:56:03 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object_base.h>

void	__update_ob(void)
{
	render().print_ob(this());
}

void	__destroy_ob(void *o)
{
	t_object *ob;

	ob = (t_object *) o;
	printf("destroy->object: %i\n", ob->type);
}

void	__render_ob(void)
{

}

t_object	*new_object(void)
{
	t_object	*o;

	o = new_object_instance(sizeof(t_object));
	return (o);
}
