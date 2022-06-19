/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/19 11:34:29 by edos-san         ###   ########.fr       */
=======
/*   Updated: 2022/06/19 02:43:07 by edos-san         ###   ########.fr       */
>>>>>>> ezequiel
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTIL_H
# define FT_UTIL_H

# include <ft_base_array.h>
# include <ft_string.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <mlx.h>
# include <ft_engine.h>
<<<<<<< HEAD
# include <ft_object.h>
=======
>>>>>>> ezequiel

# define BUFFER_SIZE 999999

typedef struct s_this
{
	t_array			*array;
	t_array			*array_main;
	t_hashmap		*hashmap;
	t_engine		*engine;
<<<<<<< HEAD
	t_object		*object;
=======
>>>>>>> ezequiel

}	t_this;

t_this		*fthis(void);

//			util
char		*get_next_line(int fd);

//			memory
int			free_ob(void *v);
int			free_list(char **str);
void		*malloc_ob(size_t __size);

//			remove - testes

#endif
