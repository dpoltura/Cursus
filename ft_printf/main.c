/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:34:14 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/16 11:32:14 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
    ft_printf("ft_printf | s : %s %s %s\n\n", "test 1", "test 2", "test 3");
    printf("printf | s : %s %s %s\n\n", "test 1", "test 2", "test 3");
    ft_printf("ft_printf | d : %d %d %d\n\n", 42, INT_MIN, INT_MAX);
    printf("printf | d : %d %d %d\n\n", 42, INT_MIN, INT_MAX);
    ft_printf("ft_printf | c : %c %c %c\n\n", 'F', 'D', 'P');
    printf("printf | c : %c %c %c\n\n", 'F', 'D', 'P');
    return (0);
}