/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidma2 <davidma2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:12:33 by davidma2          #+#    #+#             */
/*   Updated: 2024/10/24 09:44:21 by davidma2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	cont0;

	cont0 = 0;
	while (str[cont0] != '\0')
		cont0++;
	return (cont0);
}
char *ft_strjoin(char const *s1, char const *s2)
{
	size_t len1= strlen(s1);
	size_t len2 = strlen(s2);
	char *result = malloc(len1 + len2 + 1);
	if (!result)
		return NULL;
	strcpy(result, s1);
	strcat(result, s2);
	return result;
}

char *ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (char *)s;
		s++;
	}
	if (c == '\0')
		return (char *)s;
	return NULL;
}