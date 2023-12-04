/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:11:37 by dpoltura          #+#    #+#             */
/*   Updated: 2023/12/04 10:44:51 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    *buffer;
    static char    *line;
	char	*stash;
    static char    *n_line;
	int	bytes;

    line = NULL;
	stash = "";
    while (1)
    {
        line = ft_strjoin(line, n_line);
        buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!buffer)
            return (NULL);
        bytes = (int)read(fd, buffer, BUFFER_SIZE);
		if (!bytes || bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
        buffer[bytes] = '\0';
        if (!(n_line = ft_strchr(buffer, '\n')))
		{
			stash = line;
            line = ft_strjoin(stash, buffer);
		}
        else
        {
            n_line++;
            stash = ft_substr(buffer, 0, ft_n_strlen(buffer));
            line = ft_strjoin(line, stash);
            free(stash);
			stash = NULL;
            break ;
        }
    }
	free(buffer);
	buffer = NULL;
    return (line);
}