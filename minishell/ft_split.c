/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:06:46 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/15 10:02:52 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *ft_substr(const char *s, unsigned int start, size_t len)
{
        char    *str;
        size_t  i;
        size_t  j;

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

static int	count_words(char const *s, char c)
{
	int	c_w;
	int	tmp;

	tmp = 0;
	c_w = 0;
	while (*s != '\0')
	{
		if (tmp == 1 && *s == c)
			tmp = 0;
		if (tmp == 0 && *s != c)
		{
			tmp = 1;
			c_w++;
		}
		s++;
	}
	return (c_w);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;
	int		x;

	x = 0;
	if (!s)
		return (NULL);
	dest = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!dest)
		return (NULL);
	while (*s)
	{
		if (s[0] == c)
			s++;
		else
		{
			i = 0;
			while (s[i] != '\0' && s[i] != c)
				i++;
			dest[x++] = ft_substr(s, 0, i);
			s = s + i;
		}
	}
	dest[x] = NULL;
	return (dest);
}
