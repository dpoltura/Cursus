/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:14:07 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/05 15:59:16 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	putnbr(int nbr)
{
	char	c;
	long	n;
	
	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= (-1);
	}
	if (n != 0)
	{
		c = n % 10 + '0';
		putnbr(n / 10);
		write(1, &c, 1);
	}
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;
	long	k;

	i = 0;
	j = 1;
	k = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			j = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (k < INT_MIN || k > INT_MAX)
			return (-1);
		k = k * 10;
		k += nptr[i] - '0';
		i++;
	}
	if (nptr[i - 1] < '0' || nptr[i - 1] > '9')
		return (-1);
	return (k * j);
}

void	free_list(struct t_list **stack)
{
	struct t_list	*tmp;
	
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		(*stack) = tmp;
	}
}
