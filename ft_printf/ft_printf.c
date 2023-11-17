/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:58:56 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/17 12:14:50 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

int ft_printf(const char *format, ... )
{
    va_list args;
    va_start(args, format);
    int i;

    while (*format)
    {
        while (*format == '%')
        {
            if (*(format + 1) == 's')
                ft_putstr_fd(va_arg(args, char *), 1);
            else if (*(format + 1) == 'd')
                ft_putnbr_fd(va_arg(args, int), 1);
            else if (*(format + 1) == 'c')
            {
                i = va_arg(args, int);
                write(1, &i, 1);
            }
            else if (*(format + 1) == 'p')
                ft_putnbr_base_fd(va_arg(args, unsigned long), "0123456789abcdef", 1);
            else
                break;
            format += 2;
        }
        write(1, &(*format), 1);
        format++;
    }
    va_end(args);
    return (0);
}