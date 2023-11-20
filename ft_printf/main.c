/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:34:14 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/20 14:17:08 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int main(void)
{
    printf("%d : ", ft_printf("ft_printf | s : %s %s %s\n", "test 1", "test 2", "test 3"));
    printf("%d : ", printf("printf | s : %s %s %s\n", "test 1", "test 2", "test 3"));
    printf("%d : ", ft_printf("ft_printf | d : %d %d %d\n", 42, INT_MIN, INT_MAX));
    printf("%d : ", printf("printf | d : %d %d %d\n", 42, INT_MIN, INT_MAX));
    printf("%d : ", ft_printf("ft_printf | c : %c %c %c\n", '0' - 256, 'D', 'P'));
    printf("%d : ", printf("printf | c : %c %c %c\n", '0' - 256, 'D', 'P'));
    printf("%d : ", ft_printf("ft_printf | p : %p %p %p\n", "test 1", "test 2", "test 3"));
    printf("%d : ", printf("printf | p : %p %p %p\n", "test 1", "test 2", "test 3"));
    printf("%d : ", ft_printf("ft_printf | i : %i %i %i\n", 42, INT_MIN, INT_MAX));
    printf("%d : ", printf("printf | i : %i %i %i\n", 42, INT_MIN, INT_MAX));
    printf("%d : ", ft_printf("ft_printf | u : %u %u %u\n", 42, INT_MIN, INT_MAX));
    printf("%d : ", printf("printf | u : %u %u %u\n", 42, INT_MIN, INT_MAX));
    printf("%d : ", ft_printf("ft_printf | x : %x %x %x\n", 42, INT_MIN, INT_MAX));
    printf("%d : ", printf("printf | x : %x %x %x\n", 42, INT_MIN, INT_MAX));
    printf("%d : ", ft_printf("ft_printf | X : %X %X %X\n", 42, INT_MIN, INT_MAX));
    printf("%d : ", printf("printf | X : %X %X %X\n", 42, INT_MIN, INT_MAX));
    printf("%d : ", ft_printf("ft_printf | %% : %%%c%%\n", '|'));
    printf("%d : ", printf("printf | %% : %%%c%%\n", '|'));
    return (0);
}
