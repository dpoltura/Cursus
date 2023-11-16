/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:58:56 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/16 11:24:41 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *restrict format, ... )
{
    va_list args;
    va_start(args, format);
    int i;

    while (*format)
    {
        if (*format == '%')
        {
            if (*(format + 1) == 's')
                ft_putstr(va_arg(args, char *));
            else if (*(format + 1) == 'd')
                ft_putnbr(va_arg(args, int));
            else if (*(format + 1) == 'c')
            {
                i = va_arg(args, int);
                write(1, &i, 1);
            }
            format += 2;
            if (!(*format))
                break;
        }
        write(1, &(*format), 1);
        format++;
    }
    va_end(args);
    return (0);
}