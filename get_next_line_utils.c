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
#include <stdlib.h>
#include <string.h>

size_t ft_strlen(const char *str)
{
    size_t len = 0;
    while (str[len])
        len++;
    return len;
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

char *ft_strjoin(char *s1, const char *s2)
{
    size_t len1 = s1 ? ft_strlen(s1) : 0;
    size_t len2 = ft_strlen(s2);
    char *result = malloc(len1 + len2 + 1);
    if (!result)
        return NULL;
    if (s1)
    {
        strcpy(result, s1);
        free(s1);
    }
    strcpy(result + len1, s2);
    return result;
}