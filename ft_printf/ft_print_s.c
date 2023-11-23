/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:05:00 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/23 15:20:56 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int    ft_print_s(char *tmp, char *args, int j)
{
    if (!tmp)
        j += ft_putstr_fd("(null)", 1);
    j += ft_putstr_fd(args, 1);
    return (j);
}