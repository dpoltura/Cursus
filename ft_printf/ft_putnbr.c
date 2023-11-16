/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:18:18 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/16 11:19:28 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(int n)
{
	int	r;
	int	nbr;

	if (n == INT_MIN)
		write(1, "-2147483648", 11);
	if (n > INT_MIN && n <= INT_MAX)
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		r = n % 10;
		nbr = n / 10;
		r += 48;
		if (nbr > 0)
			ft_putnbr(nbr);
		write(1, &r, 1);
	}
}