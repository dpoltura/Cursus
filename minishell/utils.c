/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:11:16 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/16 12:03:35 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t  ft_strlen(const char *s)
{
        int     i;

        i = 0;
        while (s[i] != '\0')
                i++;
        return (i);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char    *ft_strjoin(const char *s1, const char *s2)
{
        char    *str;
        int             i;
        int             j;

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
        free((char *)s1);
        return (str);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (!s1[i] && !s2[i])
			return (1);
		i++;
	}
	return (0);
}

char    *ft_strdup(const char *s)
{
        int             i;
        char    *str;

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
