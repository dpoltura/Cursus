/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:11:37 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/24 15:19:10 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char    *buffer;
    static char    *res;
    size_t size;


    size = read(fd, buffer, 5);
    buffer = malloc(sizeof(char) * (size + 1));
    if (!buffer)
        return (NULL);
    res = ft_strjoin((const char *)res, (const char *)buffer);
    free(buffer);
    return (res);
}