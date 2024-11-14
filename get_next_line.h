/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidma2 <davidma2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:13:20 by davidma2          #+#    #+#             */
/*   Updated: 2024/10/24 09:44:55 by davidma2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
char	*stash_filling(int fd, char *bytesr, char *buffer);
char	*extract_new_stash(char	*bytesr);
char	*extract_line(char *bytesr, char *line);

#endif
