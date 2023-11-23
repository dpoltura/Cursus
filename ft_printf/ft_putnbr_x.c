/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:43:53 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/23 15:00:07 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_putnbr_x(unsigned int n, char *base, int fd)
{
	int	i;

	i = 0;
    if (!n)
    {
        write(fd, "0", 1);
        i = 1;
        return (i);
    }
	if (n)
	{
		if (n / ft_strlen(base))
			i += ft_putnbr_x(n / ft_strlen(base), base, fd);
		i += write(fd, &base[n % ft_strlen(base)], 1);
	}
	return (i);
}