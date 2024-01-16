/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:14:07 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/16 09:52:10 by dpoltura         ###   ########.fr       */
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
			return (0);
		k = k * 10;
		k += nptr[i] - '0';
		i++;
	}
	if (nptr[i - 1] < '0' || nptr[i - 1] > '9')
		return (0);
	return (k * j);
}

void	free_list(t_list **stack)
{
	t_list	*current;
	
	current = *stack;
	while (current)
	{
		current = current->next;
		free(*stack);
		*stack = current;	
	}
}

void	index_list(t_list **stack)
{
	t_list	*current;
	int	i;

	if (!(*stack))
		return ;
	current = *stack;
	i = 1;
	while (current)
	{
		current->index = i;
		current = current->next;
		i++;
	}
}