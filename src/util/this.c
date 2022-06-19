/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 00:06:50 by edos-san          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/19 11:37:08 by edos-san         ###   ########.fr       */
=======
/*   Updated: 2022/06/19 02:51:06 by edos-san         ###   ########.fr       */
>>>>>>> ezequiel
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

t_this	*fthis(void)
{
	static t_this	t;

	return (&t);
}

t_array	*array(t_array *a)
{
	fthis()->array = a;
	return (a);
}

t_engine	*engine(void)
{
<<<<<<< HEAD
	return (fthis()->engine);
}

=======
	return (this()->engine);
}
>>>>>>> ezequiel
