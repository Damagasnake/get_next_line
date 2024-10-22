/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidma2 <davidma2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:11:35 by davidma2          #+#    #+#             */
/*   Updated: 2024/10/22 11:17:54 by davidma2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_space(char **res, int index)
{
	while (index >= 0)
		free(res[index--]);
	free(res);
}

ssize_t	read(int fd, void buf[.count], size_t count)
{
	ssize_t	i;

	i = 0;
}

char	*get_next_line(int fd)
{
	char	*res;
	char	buffer[BUFFER_SIZE];
	ssize_t	bytesr;

#define BUFFER_SIZE 42
	index = 0;
	bytesr = read(fd, buffer, BUFFER_SIZE);
	res = (char *)malloc((bytesr + 1) * sizeof(char));
	if (!res)
		return (NULL);
}
