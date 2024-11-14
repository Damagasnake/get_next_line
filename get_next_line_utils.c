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
#include <unistd.h>
#include <stdlib.h>
size_t ft_strlen(const char *str)
{
    size_t len;
    len = 0;
    while (str[len])
        len++;
    return len;
}
char *ft_strjoin(char *s1, const char *s2)
{
    int i;
    int j;
    char *mem;

    i = 0;
    j = 0;
    mem = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) *sizeof(char));
    if(!mem)
        return (NULL);
    while (s1[i])
        mem[j++] = s1[i++];
    i = 0;
    while (s2[i])
        mem[j++] = s2[i++];
    mem[j] = 0;
    free((void *)(s1));
    return (mem);
}
char *ft_strchr(const char *s, int c)
{
    unsigned int i;

    i = 0;
    while (s[i])
    {
        if(s[i] == (char)c)
            return ((char *) &s[i]);
        i++;
    }
    if (s[i] == (char) c)
        return ((char *) &s[i]);
    return (NULL);
}
char *ft_substr(char const *s, unsigned int start, size_t len)
{
    unsigned int	i;
    char			*mem;

    i = 0;
    if (!s)
        return (NULL);
    if (start >= ft_strlen(s))
        return (malloc(1));
    if (len >= ft_strlen(s + start))
        len = ft_strlen(s + start);
    mem = malloc(sizeof(char) * (len) + 1);
    if (!mem)
        return (NULL);
    while (len > 0)
    {
        mem[i++] = s[start++];
        len--;
    }
    mem[i] = '\0';
    return (mem);
}
char	*ft_strdup(const char *s1)
{
    char	*mem;
    int		i;
    int		len;

    mem = ft_strlen(s1);
    len = 0;
    i = 0;
    mem = malloc(sizeof(char) * len + 1);
    if (!mem)
    {
        free(mem);
        return (NULL);
    }
    while (s1[i])
    {
        mem[i] = s1[i];
        i++;
    }
    mem[i] = '\0';
    free(mem);
    return (mem);
}