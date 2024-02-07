/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:01:44 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/16 13:31:11 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_b(t_list **stack_a, t_list **stack_b)
{
    t_list  *new_a;
    t_list  *new_b;

    if (!(*stack_a))
        return (0);
    if ((*stack_a)->next)
    {
        new_a = (*stack_a)->next;
        new_a->prev = NULL;
    }
    else
        new_a = NULL;
    new_b = *stack_a;
    if (*stack_b)
    {
        new_b->next = *stack_b;
        new_b = new_b->next;
        new_b->prev = *stack_a;
        new_b = new_b->prev;
    }
    else
        new_b->next = NULL;
    *stack_a = new_a;
    *stack_b = new_b;
    putstr("pb\n");
    return (1);
}

int	push_a(t_list **stack_b, t_list **stack_a)
{
    t_list  *new_a;
    t_list  *new_b;

    if (!(*stack_b))
        return (0);
    if ((*stack_b)->next)
    {
        new_b = (*stack_b)->next;
        new_b->prev = NULL;
    }
    else
        new_b = NULL;
    new_a = *stack_b;
    if (*stack_a)
    {
        new_a->next = *stack_a;
        new_a = new_a->next;
        new_a->prev = *stack_b;
        new_a = new_a->prev;
    }
    else
        new_a->next = NULL;
    *stack_a = new_a;
    *stack_b = new_b;
    putstr("pa\n");
    return (1);
}