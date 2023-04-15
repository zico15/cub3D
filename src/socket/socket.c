
#include <ft_socket.h>
#include <ft_util.h>

static void	init_socket(t_socket *s)
{
	struct hostent		*server;
	struct sockaddr_in	target;
	int					host_connect;

	server = gethostbyname(s->host);
	if (server == NULL)
		exit(0);
	s->fd = socket(AF_INET, SOCK_STREAM, 0);
	if (s->fd < 0)
		exit(0);
	bzero((char *) &target, sizeof(target));
	target.sin_family = AF_INET;
	target.sin_port = htons(atof(s->port));
	bcopy((char *)server->h_addr, \
	(char *)&target.sin_addr.s_addr, server->h_length);
	host_connect = connect(s->fd, (struct sockaddr *)&target, sizeof(target));
	if (host_connect < 0)
		exit(0);
	s->poll[0].fd = s->fd;
	s->poll[0].events = POLLIN;
}

static int	recive(t_socket *s, void (*f)(char *data))
{
	int			size;
	int			index;
	char		buffer[BUFFER_SIZE];

	index = 0;
	size = recv(s->fd, buffer, BUFFER_SIZE - 1, 0);
	index = size;
	while (size)
	{
		if (size < 0)
			return (1);
		if (size != BUFFER_SIZE)
			break ;
		size = recv(s->fd, &buffer[index], BUFFER_SIZE - 1, 0);
		index += size;
	}
	if (index < 1)
		return (0);
	buffer[index] = 0;
	s->poll[0].events = POLLIN | POLLHUP;
	s->poll[0].revents = 0;
	if (f)
		f(buffer);
	return (1);
}

void	ft_listen(t_socket *s, void (*f)(char *data))
{
	int	poll_response;

	poll_response = poll(s->poll, 1, -1);
	if (poll_response < 0)
		return ;
	if (s->poll[0].revents & POLLHUP)
	{
		printf(" disconnect...\n");
		return ;
	}
	if (s->poll[0].revents & POLLIN)
	{
		if (recive(s, f) == 1)
			return ;
		s->poll[0].events = POLLIN | POLLHUP;
		s->poll[0].revents = 0;
	}
}

void	ft_send(t_socket *s, char *message)
{
	char	*msg;

	msg = string().join(message, "\r\n");
	printf("msg: %s", msg);
	send(s->fd, msg, string().size(msg), 0);
	s->poll[0].revents = 0;
	s->poll[0].events = POLLIN | POLLOUT | POLLHUP;
	free_ob(msg);
}

t_socket	*new_socket(char *host, char *port)
{
	t_socket	*s;

	s = malloc_ob(sizeof(t_socket));
	s->host = host;
	s->port = port;
	init_socket(s);
	return (s);
}
