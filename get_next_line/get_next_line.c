/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:11:37 by dpoltura          #+#    #+#             */
/*   Updated: 2023/12/04 14:53:18 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

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
        if (!ft_strchr(buffer, '\n'))
		{
            stash = ft_strjoin(line, buffer);
			line = ft_strdup(stash);
			free(buffer);
			buffer = NULL;
		}
        else
        {
            tmp = ft_substr(buffer, 0, ft_n_strlen(buffer));
			stash = ft_strjoin(line, tmp);
			free(tmp);
			line = ft_strdup(stash);
			free(stash);
			stash = ft_strchr(buffer, '\n');
			free(buffer);
            break ;
        }
    }
    return (line);
}