/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:34:48 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/21 16:34:35 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(long n, char *base, int fd)
{
	if (n < 0 && ft_strlen(base) == 10)
	{
		ft_putchar_fd('-', 1);
		if (n == INT_MIN)
		{
				ft_putstr_fd("2147483648", 1);
				n = 0;
		}
		n *= -1;
	}
	if (n < 0 && ft_strlen(base) == 16)
		n *= -1;
	if (!n)
		return ;
	else if (n)
		ft_putnbr_base_fd(n / ft_strlen(base), base, fd);
	write(1, &base[n % ft_strlen(base)], 1);
}