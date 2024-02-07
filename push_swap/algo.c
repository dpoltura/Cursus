/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:25:43 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/07 15:05:35 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		list_size(t_list **stack)
{
	t_list	*current;
	int		i;

	current = *stack;
	i = 0;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	index_list(t_list **stack, int index)
{
	t_list	*current;
	int		smallest;

	current = *stack;
	smallest = INT_MAX;
	while (current)
	{
		if (smallest >= current->nbr && current->index == 0)
			smallest = current->nbr;
		current = current->next;
	}
	current = *stack;
	while (current->nbr != smallest)
		current = current->next;
	current->index = index;
}

int		algo(t_list **stack_a, t_list **stack_b, int index)
{
	t_list	*current;
	int		size;
	int		i;
	int		j;
	int		op;

	op = 0;
	size = list_size(stack_a);
	i = index;
	while (i <= size)
	{
		index_list(stack_a, i);
		i++;
	}
	while (*stack_a)
	{
		current = *stack_a;
		i = index;
		j = 1;
		while (current->index != i)
		{
			current = current->next;
			j++;
		}
		while ((*stack_a)->index != i)
		{
			if (j > size / 2)
				op += reverse_rotate(stack_a, 1);
			else
				op += rotate(stack_a, 1);
		}
		op += push_b(stack_a, stack_b);
		index++;
	}
	while (*stack_b)
		op += push_a(stack_b, stack_a);
	return (op);
}