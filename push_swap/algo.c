/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:25:43 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/12 14:31:09 by dpoltura         ###   ########.fr       */
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

int		check_if_sorted(t_list **stack)
{
	t_list	*first;
	t_list	*next;
	
	first = *stack;
	next = (*stack)->next;
	while (next)
	{
		if (first->index > next->index)
			return (1);
		first = first->next;
		next = next->next;
	}
	return (0);
}

void    radix_sort(t_list **stack_a, t_list **stack_b)
{
   	int        bit;
	int        max_nb;
	int		i;

    max_nb = list_size(stack_a);
    bit = 0;
	i = 1;
	while (i <= max_nb)
	{
		index_list(stack_a, i);
		i++;
	}
    while (check_if_sorted(stack_a) == 1)
    {
		i = 0;
        while (i < max_nb && (*stack_a))
        {
            if ((((*stack_a)->index >> bit) & 1) == 1)
                rotate(stack_a, 1);
            else
                push_b(stack_a, stack_b);
			i++;
        }
        while (list_size(stack_b))
            push_a(stack_b, stack_a);
        bit++;
    }
}