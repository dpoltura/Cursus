/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:12:55 by dpoltura          #+#    #+#             */
/*   Updated: 2023/12/04 16:28:38 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char *ptr, size_t size)
{
	int	len;
	char	*s;
	int	i;

	i = 0;
	len = ft_strlen(ptr);
	size += len + 1;
	s = malloc(sizeof(char) * size);
	if (!s)
		return (NULL);
	while (ptr[i] != '\0')
	{
		s[i] = ptr[i];
		i++;
	}
	s[i] = '\0';
	free(ptr);
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (c > 256)
		c -= 256;
	while (s[i] != '\0')
		i++;
	while (s[j] != c)
	{
		j++;
		if (s[j] == '\0' && s[j] != c)
			return (NULL);
	}
	return ((char *)s + (j + 1));
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && j < len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

int	ft_strnlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n')
		i++
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2)
		return ((char *)s1);
	if (!s1)
		return ((char *)s2);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}