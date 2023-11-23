/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:34:48 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/23 11:32:02 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_fd(long n, char *base, int fd)
{
	int	i;

	i = 0;
	if (n < 0 && ft_strlen(base) == 10)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	else if (!n)
	{
		if (ft_strlen(base) == 10)
		{
			ft_putchar_fd('0', fd);
			i++;
		}
		return (i);
	}
	else if (n || n < 0)
	{
		i = ft_putnbr_base_fd(n / ft_strlen(base), base, fd);
		i += write(fd, &base[n % ft_strlen(base)], 1);
	}
	return (i);
}