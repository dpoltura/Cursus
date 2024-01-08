/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:09:21 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/08 11:30:31 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(struct t_list **stack)
{
    struct t_list   *first;
    int a;
    int b;
    
    if (!(*stack) || !(*stack)->next)
        return ;
    first = *stack;
    a = first->nbr;
    *stack = (*stack)->next;
    b = (*stack)->nbr;
    first->nbr = b;
    (*stack)->nbr = a;
    *stack = first;
}

void    swap_all(struct t_list *stack_a, struct t_list *stack_b)
{
    swap(&stack_a);
    swap(&stack_b);
}
