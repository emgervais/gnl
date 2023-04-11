/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:54:51 by egervais          #+#    #+#             */
/*   Updated: 2023/02/14 19:11:03 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_line(char *buffer, char **line)
{
	size_t	b;
	size_t	i;

	b = 0;
	while (buffer[b] && buffer[b] != '\n')
		b++;
	if (buffer[b] == '\n')
		b++;
	*line = (char *)malloc((b + 1) * sizeof(char));
	if (!*line)
		return (0);
	i = 0;
	while (i < b)
	{
		(*line)[i] = buffer[i];
		i++;
	}
	(*line)[i] = 0;
	return (b);
}

char	*ft_join(char *buffer, char *buf, size_t *size)
{
	char	*temp;

	if (!buffer)
	{
		*size += ft_strlen(buf) * (*size < ft_strlen(buf));
		buffer = (char *)malloc(*size + 1);
		if (!buffer)
			return (NULL);
		ft_strcpy(buffer, buf);
		return (buffer);
	}
	temp = buffer;
	if (*size < ft_strlen(buffer) + ft_strlen(buf))
	{
		while (*size < ft_strlen(buffer) + ft_strlen(buf))
			*size *= 2;
		temp = (char *)malloc(*size + 1);
		if (temp)
			ft_strcpy(temp, buffer);
		free(buffer);
		if (!temp)
			return (NULL);
	}
	ft_strcpy(temp + ft_strlen(temp), buf);
	return (temp);
}

static void	readf(int fd, char **end)
{
	int		check;
	char	*buffer;
	size_t	size;

	size = 256;
	buffer = (char *)malloc((BUFFER_SIZE + 1));
	check = 0;
	while (buffer)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check <= 0)
			break ;
		buffer[check] = 0;
		end[fd] = ft_join(end[fd], buffer, &size);
		if (ft_strchr(buffer, '\n') || !end[fd])
			break ;
	}
	if ((check == -1 && end[fd]) || !buffer)
	{
		free(end[fd]);
		end[fd] = 0;
	}
	free(buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX] = {0};
	char		*line;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 10001)
		return (NULL);
	readf(fd, buffer);
	if (buffer[fd] && buffer[fd][0])
	{
		len = ft_line(buffer[fd], &line);
		if (!len)
		{
			free(buffer[fd]);
			buffer[fd] = 0;
			return (NULL);
		}
		ft_strcpy(buffer[fd], &(buffer[fd][len]));
		return (line);
	}
	free(buffer[fd]);
	buffer[fd] = 0;
	return (0);
}
