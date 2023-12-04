/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:11:37 by dpoltura          #+#    #+#             */
/*   Updated: 2023/12/04 16:31:39 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
	char	*buf;
	int	bytes;
	static char	*line = NULL;
	char	*tmp;

	while (1)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		bytes = read(fd, buf, BUFFER_SIZE);
		if (!bytes || bytes < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes] = 0;
		if (!ft_strchr(buf, '\n'))
		{
			tmp = ft_strjoin(line, buf);
			line = ft_realloc(tmp, BUFFER_SIZE);
		}
		else
		{
			tmp = ft_substr(buf, 0, ft_strnlen(buf));
			line = ft_realloc(tmp, 0);
			tmp = ft_strchr(buf)
			free(buf);
			break ;
		}
	}
    return (line);
}