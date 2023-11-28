/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:11:37 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/28 10:12:31 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    *buffer;
    static char    *line;
    static char    *n_line;

    if (!line)
    {
        line = malloc(1);
        if (!line)
            return (NULL);
    }
    read(fd, buffer, BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    //ft_strchr(buffer, '\n');
    buffer[BUFFER_SIZE + 1] = 0;
    line = ft_strjoin(line, buffer);
    return (line);
}