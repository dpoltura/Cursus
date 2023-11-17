/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:34:48 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/17 14:24:26 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_reverse(char *res)
{
	char	*tmp;
	int	i;

	i = ft_strlen(res);
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	while (i > 0)
	{
		i--;
		*tmp = *(res + i);
		tmp++;
	}
	*tmp = 0;
	res = tmp - ft_strlen(res);
	return (res);
}

void	ft_putnbr_base_fd(long n, char *base, int fd)
{
	char	*res;
	int	i;

	i = 0;
	res = malloc(sizeof(char) * 255);
	if (!res)
		return ;
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
	while (n)
	{
		*(res + i) = *(base + (n % ft_strlen(base)));
		n = n / ft_strlen(base);
		i++;
	}
	*(res + i) = 0;
	res = ft_reverse(res);
	ft_putstr_fd(res, fd);
	free(res);
}