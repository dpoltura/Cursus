/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:11:37 by dpoltura          #+#    #+#             */
/*   Updated: 2023/12/04 14:01:20 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    *buffer;
    char    *line;
	static char	*stash = NULL;
	char	*tmp;
	int	bytes;

	line = NULL;
	buffer = NULL;
	tmp = NULL;
	bytes = 0;
    while (1)
    {
		if (!buffer)
		{
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
		}
		if (!line)
		{
			line = malloc(1);
			if (!line)
				return (NULL);
		}
        if (!ft_strchr(buffer, '\n'))
		{
            stash = ft_strjoin(line, buffer);
			line = ft_strdup(stash);
			free(buffer);
			buffer = NULL;
			free(stash);
			stash = NULL;
		}
        else
        {
            tmp = ft_substr(buffer, 0, ft_n_strlen(buffer));
			stash = ft_strjoin(line, tmp);
			free(tmp);
			tmp = NULL;
			line = ft_strdup(stash);
			free(stash);
			stash = ft_strchr(buffer, '\n');
			free(buffer);
			buffer = NULL;
            break ;
        }
    }
    return (line);
}