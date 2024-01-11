/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:01:44 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/10 11:26:17 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_b(struct t_list **stack_a, struct t_list **stack_b)
{
    struct t_list   *new_a;
    struct t_list   *new_b;

    if (!(*stack_a))
        return (0);
    new_b = (struct t_list *)malloc(sizeof(struct t_list));
    if (!new_b)
        error();
    new_b->nbr = (*stack_a)->nbr;
    new_b->next = *stack_b;
    *stack_b = new_b;
    new_a = (*stack_a)->next;
    free(*stack_a);
    *stack_a = new_a;
    putstr("pb\n");
    return (1);
}

int	push_a(struct t_list **stack_b, struct t_list **stack_a)
{
    struct t_list   *new_a;
    struct t_list   *new_b;

    if (!(*stack_b))
        return (0);
    new_a = (struct t_list *)malloc(sizeof(struct t_list));
    if (!new_a)
        error();
    new_a->nbr = (*stack_b)->nbr;
    new_a->next = *stack_a;
    *stack_a = new_a;
    new_b = (*stack_b)->next;
    free(*stack_b);
    *stack_b = new_b;
    putstr("pa\n");
    return (1);
}