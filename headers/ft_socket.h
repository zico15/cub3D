/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_socket.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:00:20 by edos-san          #+#    #+#             */
/*   Updated: 2023/04/17 15:15:37 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_SOCKET_H
# define FT_SOCKET_H

# include <sys/socket.h>
# include <netinet/in.h>
# include <unistd.h>
# include <string.h>
# include <sys/poll.h>
# include <stdlib.h>
# include <netdb.h>

typedef struct ft_socket
{
	int					fd;
	char				*host;
	char				*port;
	struct pollfd		poll[1];
}	t_socket;

t_socket	*new_socket(char *host, char *port);
void		ft_send(t_socket *s, char *message);
void		ft_listen(t_socket *s, void (*f)(char *data));

#endif