/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:34:48 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/21 11:51:33 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long n)
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
	free(res);
	return (tmp);
}

void	ft_putnbr_base_fd(long n, char *base, int fd)
{
	char	*res;
	int	i;

	i = 0;
	res = malloc(sizeof(char) * (ft_numlen(n) + 1));
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
	if (!n)
		n = 1;
	while (n)
	{
		*(res + i) = *(base + (n % ft_strlen(base)));
		n = n / ft_strlen(base);
		i++;
	}
	*(res + i) = 0;
	ft_putstr_fd(ft_reverse(res), fd);
	free(res);
}