/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:09:21 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/16 16:19:24 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack, int choice)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!(*stack) || !(*stack)->next)
		return (0);
	first = *stack;
	second = (*stack)->next;
	third = NULL;
	if (second->next)
	{
		third = second->next;
		third->prev = first;
	}
	if (third)
		first->next = third;
	else
		first->next = NULL;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (choice == 1)
		putstr("sa\n");
	else if (choice == 2)
		putstr("sb\n");
	*stack = second;
	return (1);
}

int	swap_all(t_list **stack_a, t_list **stack_b)
{
	if (!swap(stack_a, 0) && !swap(stack_b, 0))
		return (0);
	putstr("ss\n");
	return (1);
}
