/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:15:32 by egervais          #+#    #+#             */
/*   Updated: 2023/02/13 17:53:11 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	//if (!line)
	//{
	//	free(buffer);
	//	buffer = 0;
	//	return (ERROR);
	//}
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char *ft_line(char *buffer)
{
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}
}


char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char *readf(int fd, char *end)
{
	int check;
	char *buffer;

	if (!end)
		end = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	check = 0;
	while (buffer)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check <= 0)
			break ;
		buffer[check] = 0;
		end = ft_free(end, buffer);
		if (ft_strchr(buffer, '\n') || !end)
			break;
	}
	if ((check == -1 && end) || !buffer)
	{
		free(end);
		free(buffer);
		return (NULL);
	}
	free(buffer);
	return (end);
}

char *get_next_line(int fd)
{
    static char *buffer;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    buffer = readf(fd, buffer);
    if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	if(!line)
	{
		free (buffer);
		buffer = 0;
		return (NULL);
	}
	buffer = ft_next(buffer);
	//if (buffer == ERROR)
	//	return (NULL);
	return (line);
}