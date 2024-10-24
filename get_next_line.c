/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidma2 <davidma2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:11:35 by davidma2          #+#    #+#             */
/*   Updated: 2024/10/24 13:03:49 by davidma2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_space(char *res, int index)
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
