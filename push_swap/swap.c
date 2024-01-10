/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:09:21 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/10 11:31:14 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(struct t_list **stack)
{
    struct t_list   *first;
    int a;
    int b;
    
    if (!(*stack) || !(*stack)->next)
        return (0);
    first = *stack;
    a = first->nbr;
    *stack = (*stack)->next;
    b = (*stack)->nbr;
    first->nbr = b;
    (*stack)->nbr = a;
    *stack = first;
    putstr("sa/b\n");
    return (1);
}

int    swap_all(struct t_list *stack_a, struct t_list *stack_b)
{
    if (!swap(&stack_a))
        return (0);
    if (!swap(&stack_b))
        return (0);
    putstr("sAll\n");
    return (1);
}
