/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/19 01:55:57 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>
# include <ft_util.h>

typedef struct s_string
{
	int		(*contains)(const char *str, const char *hey);
	int		(*size)(const char *s);
	char	*(*copy)(const char *str);
	char	*(*join)(const char *str1, const char *str2);
	char	*(*copy_n)(const char *str, int n);
	char	*(*trim)(const char *str);
	int		(*equals)(const char *str1, const char *str2);
	int		(*equals_n)(const char *str, const char *hey, int n);
	int		(*is_space)(char c);
	char	*(*strnstr)(const char *haystack, const char *needle, size_t len);
	int		(*size_list)(char **list);
	char	*(*replace)(const char *str1, const char *str2, const char *hey);
	int		(*isalnum)(char c);
	char	**(*split)(char const *s, char *spacer);
	char	*(*itoa)(int n);
	int		(*atoi)(const char *v);
	int		(*isnumber)(const char *str);
}	t_string;

t_string	string(void);
char		*_str(const char c);

#endif
