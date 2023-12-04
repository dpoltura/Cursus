/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:16:20 by dpoltura          #+#    #+#             */
/*   Updated: 2023/12/04 15:20:51 by dpoltura         ###   ########.fr       */
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
    while (i < 2)
    {
        line = get_next_line(fd);
        printf("%s\n", line);
        i++;
    }
    return (0);
}