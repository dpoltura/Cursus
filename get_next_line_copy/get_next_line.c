/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:11:37 by dpoltura          #+#    #+#             */
/*   Updated: 2023/12/05 10:03:15 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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
	static char	*buf = NULL;
	int	bytes;
	char	*line;
	char	*tmp;

	line = NULL;
	tmp = NULL;
	while (1)
	{
		if (buf)
			line = ft_strdup(buf);
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
			buf = NULL;
		}
		else
		{
			tmp = ft_strjoin(line, ft_substr(buf, 0, ft_strnlen(buf)));
			line = ft_realloc(tmp, 0);
			buf = ft_strchr(buf, '\n');
			break ;
		}
	}
	return (line);
}
