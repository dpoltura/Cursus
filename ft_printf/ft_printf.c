/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:58:56 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/21 16:00:47 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int ft_printf(const char *format, ... )
{
    va_list args;
    va_list tmp;
    va_start(args, format);
    va_copy(tmp, args);
    int i;
    int j;

    j = 0;
    while (*format)
    {
        while (*format == '%')
        {
            format++;
            if (*(format) == 's')
            {
                if (!va_arg(tmp, char *))
                    j += ft_putstr_fd("(null)", 1);
                j += ft_putstr_fd(va_arg(args, char *), 1);
            }
            else if (*(format) == 'd')
                j += ft_putnbr_fd(va_arg(args, int), 1);
            else if (*(format) == 'c')
            {
                i = va_arg(args, int);
                j += write(1, &i, 1);
            }
            else if (*(format) == 'p')
            {
                j += ft_putstr_fd("0x", 1);
                ft_putnbr_base_fd(va_arg(args, unsigned long), "0123456789abcdef", 1);
            }
            else if (*(format) == 'i')
                ft_putnbr_base_fd(va_arg(args, int), "0123456789", 1);
            else if (*(format) == 'u')
                ft_putnbr_base_fd(va_arg(args, unsigned int), "0123456789", 1);
            else if (*(format) == 'x')
                ft_putnbr_base_fd(va_arg(args, int), "0123456789abcdef", 1);
            else if (*(format) == 'X')
                ft_putnbr_base_fd(va_arg(args, int), "0123456789ABCDEF", 1);
            else if (*(format) == '%')
                ft_putchar_fd('%', 1);
            else
                break;
            format++;
        }
        if (*(format))
        {
            write(1, &(*format), 1);
            format++;
            j++;
        }
    }
    va_end(args);
    va_end(tmp);
    return (j);
}