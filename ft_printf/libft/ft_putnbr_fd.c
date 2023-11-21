/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:34:48 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/21 10:28:54 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	r;
	int	nbr;
	int	i;

	i = 0;
	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		i += 11;
	}
	if (n > INT_MIN && n <= INT_MAX)
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
			i++;
		}
		r = n % 10;
		nbr = n / 10;
		r += 48;
		if (nbr > 0)
			ft_putnbr_fd(nbr, fd);
		write(fd, &r, 1);
		if (n == 0)
			n++;
	}
	return (ft_numlen(n) + i);
}
