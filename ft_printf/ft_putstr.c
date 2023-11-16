/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:10:24 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/16 10:20:58 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int  ft_strlen(char *str)
{
    int i;

    i = 0;
    while (*str)
    {
        i++;
        str++;
    }
    return (i);
}

void    ft_putstr(char *str)
{
    int i;
    
    i = 0;
    while (i < ft_strlen(str))
    {
        write(1, &*(str + i), 1);
        i++;
    }
}