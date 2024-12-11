/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokuyos <ctokuyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:05:52 by ctokuyos          #+#    #+#             */
/*   Updated: 2024/12/11 17:07:06 by ctokuyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*free_buffer(char **buf)
{
	if (*buf)
	{
		free(*buf);
		*buf = NULL;
	}
	return (NULL);
}

static char	*get_line(int fd, char *buffer, char *rest)
{
	ssize_t	size;
	char	*temp;

	size = 1;
	while (size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
			return (NULL);
		if (size == 0)
			break ;
		buffer[size] = '\0';
		if (!rest)
			rest = ft_strdup("");
		temp = rest;
		rest = ft_strjoin(temp, buffer);
		free_buffer(&temp);
		if (ft_strchr(rest, '\n'))
			break ;
	}
	return (rest);
}

static char	*get_next_line_tail(char *line)
{
	int		index;
	char	*rest;

	index = 0;
	while (line[index] != '\0' && line[index] != '\n')
		index++;
	if (line[index] == '\n')
		index++;
	if (line[index] == '\0')
		return (NULL);
	rest = ft_strdup(line + index);
	line[index] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest[4242];
	char		*buffer;
	char		*line;

	if (fd == -1 || fd >= 4242 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	line = get_line(fd, buffer, rest[fd]);
	free_buffer(&buffer);
	if (!line)
	{
		free_buffer(&rest[fd]);
		return (NULL);
	}
	rest[fd] = get_next_line_tail(line);
	return (line);
}
