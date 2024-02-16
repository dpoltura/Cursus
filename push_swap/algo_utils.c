/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:09:19 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/16 16:00:46 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_size(t_list **stack)
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

int	check_if_sorted(t_list **stack)
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
