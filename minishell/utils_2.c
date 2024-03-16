/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:51:24 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/16 12:03:17 by dpoltura         ###   ########.fr       */
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
