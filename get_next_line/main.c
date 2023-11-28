/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:16:20 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/28 10:13:08 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int    main(void)
{
    int    i;
    int    fd;
    char    *line;

    i = 0;
    fd = open("test.txt", O_RDONLY);
    while (i < 20)
    {
        line = get_next_line(fd);
        i++;
    }
    printf("%s\n", line);
    free(line);
    return (0);
}