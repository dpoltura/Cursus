/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:11:37 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/29 14:18:37 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    *buffer;
    static char    *line;
    static char    *n_line;
    char    *tmp;

    line = NULL;
    while (1)
    {
        line = ft_strjoin(line, n_line);
        buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!buffer)
            return (NULL);
        read(fd, buffer, BUFFER_SIZE);
        buffer[BUFFER_SIZE] = 0;
        if (!(n_line = ft_strchr(buffer, '\n')))
            line = ft_strjoin(line, buffer);
        else
        {
            n_line++;
            tmp = ft_substr(buffer, 0, ft_n_strlen(buffer));
            line = ft_strjoin(line, tmp);
            free(tmp);
            break ;
        }
    }
    return (line);
}