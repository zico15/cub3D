/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/19 02:00:55 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_UTIL_H
# define STRING_UTIL_H

# include <ft_util.h>

char		*__join(const char *str1, const char *str2);
char		**__split(char const *s, char *c, int j, char **list);
char		*__copy_n(const char *str, int n);
char		*__str_trim(const char *str);
int			__equals(const char *str1, const char *str2);
int			__equals_n(const char *str1, const char *str2, int n);
int			__is_space(char c);
char		*__strnstr(const char *haystack, const char *needle, size_t len);
int			__size_list(char **list);
char		*__replace(const char *str1, const char *str2, const char *hey);
int			__isalnum(char c);
char		**__split_spacer(char const *s, char *spacer);
char		*__itoa(int n);
int			__atoi(const char *v);

#endif
