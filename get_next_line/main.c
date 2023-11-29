/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:16:20 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/29 14:13:55 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int    main(void)
{
    int    i;
    int    fd;
    char    *line;

    i = 0;
    fd = open("test.txt", O_RDONLY);
    while (i < 3)
    {
        line = get_next_line(fd);
        printf("%s\n", line);
        free(line);
        i++;
    }
    return (0);
}