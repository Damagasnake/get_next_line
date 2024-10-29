]]/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidma2 <davidma2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:11:35 by davidma2          #+#    #+#             */
/*   Updated: 2024/10/28 17:18:04 by davidma2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*static void	free_space(char *res, int index)
{
	while (index >= 0)
		free(res[index--]);
	free(res);
}

char	*get_next_line(int fd)
{
	char	*res;
	char	buffer[BUFFER_SIZE];
	ssize_t	bytesr;
	int		i;

	i = 0;
	bytesr = read(fd, buffer, BUFFER_SIZE);
	res = (char *)malloc((bytesr + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < bytesr && buffer[i] != '\n')
	{
		res[i] = buffer[i];
		i++;
	}
	res[i] = '\0';
}
*/
static char *returnline(char *buf)
{
	char *newline;
	size_t i;
	size_t j;
	
	i = 0;
	if (!buf)
		return(NULL);
	while (buf[i] && buf[i] != '\n')
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
		j++;
	}
	if (buf[i] == '\n')
		newline[j++] = '\n';
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
