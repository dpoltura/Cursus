/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:16:20 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/24 10:15:45 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int    main(void)
{
    int    fd;
    int    i;
    char    *res;

    i = 0;
    fd = open("test.txt", 'r');
    while (i < 5)
    {
        res = get_next_line(fd);
        i++;
    }
    printf("%s\n", res);
    free(res);
    return (0);
}