/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:09:04 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/19 18:09:04 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BASE_ARRAY_UTIL_H
# define FT_BASE_ARRAY_UTIL_H

# include <stdio.h>
# include <stdlib.h>
# include <ft_base_array.h>

void			__base_for_each(void (*fun)(t_element *e, void *v), void *o);
t_element		*__base_set_element(int index, void *value);
void			__base_remove_element_index(int index);
int				__base_free_element(void *value);
void			**__to_str(void);
void			__destroy_element(t_element	*e);

//				hashmap
t_element		*__put_hasmap(char *key, void	*value);
t_element		*__get_index_hasmap(int index);
t_element		*__get_key_hasmap(char *key);
void			__remove_index_hasmap(int index);
void			__remove_element_hasmap(char	*key);
void			**__to_str_hashmpa(void);
#endif
