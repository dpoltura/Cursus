/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:14:07 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/21 16:47:33 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putstr(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
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

int	ft_atoi(const char *nptr, t_list **stack_a, t_bool *boolean, char **argv)
{
	int		i;
	int		j;
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
	if (nptr[i] == '\0')
		error(stack_a, boolean, argv);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		k = k * 10;
		k += nptr[i] - '0';
		if ((k * j) < INT_MIN || (k * j) > INT_MAX)
			error(stack_a, boolean, argv);
		i++;
	}
	while (nptr[i] == 32)
		i++;
	if (nptr[i] != '\0')
		error(stack_a, boolean, argv);
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
