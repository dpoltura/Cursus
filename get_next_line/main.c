/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:16:20 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/24 09:29:22 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int    main(void)
{
    int    fd;
    char    *res;

    fd = open("test.txt", 'r');
    res = get_next_line(fd);
    printf("%s\n", res);
    return (0);
}