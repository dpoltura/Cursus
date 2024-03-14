/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:11:16 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/14 12:26:15 by dpoltura         ###   ########.fr       */
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
        return (str);
}

char	*check_path(char **split_path, char *input)
{
	int	i;
	char	*full_path;

	i = 0;
	while (split_path[i])
	{
		full_path = ft_strjoin(split_path[i], "/");
		full_path = ft_strjoin(full_path, input);
		if (access(full_path, F_OK) == -1)
			free(full_path);
		else if (access(full_path, F_OK) == 0)
			return (full_path);
		i++;
	}
	return (NULL);
}
