/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:58:56 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/16 10:20:30 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *restrict format, ... )
{
    va_list args;
    va_start(args, format);
    char    *str;

    while (*format)
    {
        if (*format == '%' && *(format + 1) == 's')
        {
            str = va_arg(args, char *);
            format += 2;
            ft_putstr(str);
            if (!(*format))
                break;
        }
        write(1, &(*format), 1);
        format++;
    }
    va_end(args);
    return (0);
}