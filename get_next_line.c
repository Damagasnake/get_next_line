/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidma2 <davidma2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:11:35 by davidma2          #+#    #+#             */
/*   Updated: 2024/10/28 14:12:28 by davidma2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
static char *returnline(char *buf)
{
	char *newline;
	size_t i;
	size_t j;

	i = 0;
	if (!buf)
		return(NULL);
		i++;
	if (buf[i] == '\n')
		newline = (char *)malloc((i + 2) * sizeof(char));
	else
		newline = (char *)malloc((i + 1) * sizeof(char));
	if (!newline)
		return(NULL);
	j = 0;
	while (j < i)
	{
		newline[j] = buf[j];
	while (buf[i] && buf[i] != '\n')
		j++;
	}
	if (buf[i] == '\n')
	{
		newline[j] = '\n';
		j++;
	}
	newline[j] = '\0';
	return (newline);
}
static char *nextbuff(char *buf)
{
	char *secondBuffer;
	size_t i;
	size_t j;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return(NULL);
	}
	secondBuffer = (char *)malloc(ft_strlen(buf) - i);
	if (!secondBuffer)
	{
		free(secondBuffer);
		return(NULL);
	}
	i++;
	j = 0;
	while (buf[i])
		secondBuffer[j++] = buf[i++];
	secondBuffer[j] = '\0';
	free(buf);
	return(secondBuffer);
}
char *get_next_line(int fd)
{
	static char *buffer;
	char *newline;
	char temp_buffer[BUFFER_SIZE + 1];
	ssize_t bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while ((bytes_read = read(fd, temp_buffer, BUFFER_SIZE)) > 0)
	{
		temp_buffer[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, temp_buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (bytes_read < 0 || (bytes_read == 0 && (!buffer || !*buffer)))
		return (NULL);
	newline = returnline(buffer);
	buffer = nextbuff(buffer);
	return (newline);
}