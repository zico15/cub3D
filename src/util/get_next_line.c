/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:28:31 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/19 01:23:04 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

typedef struct s_line
{
	char			*line;
	long			size_line;
	long			index;
	long			size_buffer;
	long			size_read;
	struct s_line	*v;
}	t_line;

char	*get_line(char *line, char *buffer, long size_buffer, long *size_line)
{
	t_line	data;

	data.size_line = -1;
	data.index = -1;
	data.size_buffer = -1;
	data.line = line;
	*size_line += size_buffer;
	line = malloc_ob(*size_line + 1 * sizeof(char));
	if (line)
	{
		line[*size_line] = 0;
		while (data.line && data.line[++data.size_line])
			line[++data.index] = data.line[data.size_line];
		data.size_line = -1;
		while (buffer && buffer[++data.size_line])
		{
			if (data.size_line < size_buffer)
				line[++data.index] = buffer[data.size_line];
			else
				buffer[++data.size_buffer] = buffer[data.size_line];
			buffer[data.size_line] = 0;
		}
	}
	free_ob(data.line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	f[BUFFER_SIZE + 1];
	t_line		d;

	d.line = NULL;
	d.size_buffer = 0;
	d.index = 1;
	while (fd >= 0 && f[d.size_buffer])
		d.size_buffer++;
	d.size_line = 0;
	while (fd >= 0 && d.index > 0)
	{
		if (!f[0] || !d.size_buffer)
			d.size_buffer = read(fd, f, BUFFER_SIZE);
		d.index = d.size_buffer;
		if (d.size_buffer > 0)
		{
			d.size_buffer = 0;
			while (f[d.size_buffer] && f[d.size_buffer] != '\n')
				d.size_buffer++;
			d.index = (d.index == d.size_buffer);
			d.size_buffer += f[d.size_buffer] == '\n';
			d.line = get_line(d.line, f, d.size_buffer, &d.size_line);
		}
	}
	return (d.line);
}
