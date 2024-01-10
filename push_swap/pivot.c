/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:14:30 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/10 11:44:23 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pivot_three(struct t_list **stack)
{
	struct t_list	*first;
	struct t_list	*pivot;
	struct t_list	*last;
    int op;

	first = *stack;
	pivot = (*stack)->next;
	last = pivot->next;
	if (first->nbr < pivot->nbr && pivot->nbr < last->nbr && last->nbr > first->nbr)
		return (0);
	else if (first->nbr < pivot->nbr && pivot->nbr > last->nbr && last->nbr < first->nbr)
		op = reverse_rotate(stack);
	else if (first->nbr > pivot->nbr && pivot->nbr < last->nbr && last->nbr < first->nbr)
		op = rotate(stack);
	else if (first->nbr > pivot->nbr && pivot->nbr > last->nbr && last->nbr < first->nbr)
	{
		op = rotate(stack);
		op += swap(stack);
	}
	else if (first->nbr < pivot->nbr && pivot->nbr > last->nbr && last->nbr > first->nbr)
	{
		op = reverse_rotate(stack);
		op += swap(stack);
	}
	else if (first->nbr > pivot->nbr && pivot->nbr < last->nbr && last->nbr > first->nbr)
		op = swap(stack);
    return (op);
}

int	pivot_two(struct t_list **stack)
{
	struct t_list	*first;
	struct t_list	*last;
    int op;

	first = *stack;
	last = (*stack)->next;
	if (first->nbr < last->nbr)
		return (0);
	else if (first->nbr > last->nbr)
		op = rotate(stack);
	return (op);
}
