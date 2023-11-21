/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:34:14 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/21 15:13:51 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int main(void)
{
    printf("%d\n", ft_printf("ft_printf | s : %s %s %s | ", "test 1", "test 2", "test 3"));
    printf("%d\n", printf("printf | s : %s %s %s | ", "test 1", "test 2", "test 3"));
    printf("%d\n", ft_printf("ft_printf | d : %d %d %d | ", 42, INT_MIN, INT_MAX));
    printf("%d\n", printf("printf | d : %d %d %d | ", 42, INT_MIN, INT_MAX));
    printf("%d\n", ft_printf("ft_printf | c : %c %c %c | ", '0' - 256, 'D', 'P'));
    printf("%d\n", printf("printf | c : %c %c %c | ", '0' - 256, 'D', 'P'));
    printf("%d\n", ft_printf("ft_printf | p : %p %p %p | ", "test 1", "test 2", "test 3"));
    printf("%d\n", printf("printf | p : %p %p %p | ", "test 1", "test 2", "test 3"));
    printf("%d\n", ft_printf("ft_printf | i : %i %i %i | ", 42, INT_MIN, INT_MAX));
    printf("%d\n", printf("printf | i : %i %i %i | ", 42, INT_MIN, INT_MAX));
    printf("%d\n", ft_printf("ft_printf | u : %u %u %u | ", 42, INT_MIN, INT_MAX));
    printf("%d\n", printf("printf | u : %u %u %u | ", 42, INT_MIN, INT_MAX));
    printf("%d\n", ft_printf("ft_printf | x : %x %x %x | ", 42, INT_MIN, INT_MAX));
    printf("%d\n", printf("printf | x : %x %x %x | ", 42, INT_MIN, INT_MAX));
    printf("%d\n", ft_printf("ft_printf | X : %X %X %X | ", 42, INT_MIN, INT_MAX));
    printf("%d\n", printf("printf | X : %X %X %X | ", 42, INT_MIN, INT_MAX));
    printf("%d\n", ft_printf("ft_printf | %% : %%%c%% | ", '|'));
    printf("%d\n", printf("printf | %% : %%%c%% | ", '|'));
    return (0);
}
