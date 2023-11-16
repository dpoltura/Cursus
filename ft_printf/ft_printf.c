/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:58:56 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/16 09:50:36 by dpoltura         ###   ########.fr       */
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
        if (*format == '%' && *(format + 1) == 'c')
        {
            i = va_arg(args, int);
            format += 2;
            printf("%c", i);
            if (!(*format))
                break;
        }
        printf("%c", *format);
        format++;
    }
    va_end(args);
    return (0);
}