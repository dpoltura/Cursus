/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:23:11 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/10 11:30:00 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    reverse_rotate(struct t_list **stack)
{
    struct t_list   *current;
    struct t_list   *last;
    struct t_list   *first;

    if (!(*stack) || !(*stack)->next)
        return (0);
    current = *stack;
    last = *stack;
    while ((*stack)->next)
        *stack = (*stack)->next;
    first = (struct t_list *)malloc(sizeof(struct t_list));
    if (!first)
        error();
    first->nbr = (*stack)->nbr;
    while (last->next != *stack)
        last = last->next;
    last->next = NULL;
    first->next = current;
    free(*stack);
    *stack = first;
    putstr("rra/b\n");
    return (1);
}

int    rotate(struct t_list **stack)
{
    struct t_list   *first;
    struct t_list   *current;

    if (!(*stack) || !(*stack)->next)
        return (0);
    first = (*stack)->next;
    current = (*stack)->next;
    while (current->next)
        current = current->next;
    current->next = (struct t_list *)malloc(sizeof(struct t_list));
    if (!current->next)
        error();
    current = current->next;
    current->nbr = (*stack)->nbr;
    current->next = NULL;
    free(*stack);
    *stack = first;
    putstr("ra/b\n");
    return (1);
}

int    reverse_rotate_all(struct t_list **stack_a, struct t_list **stack_b)
{
    if (!reverse_rotate(stack_a))
        return (0);
    if (!reverse_rotate(stack_b))
        return (0);
    putstr("rrAll\n");
    return (1);
}

int    rotate_all(struct t_list **stack_a, struct t_list **stack_b)
{
    if (!rotate(stack_a))
        return (0);
    if (!rotate(stack_b))
        return (0);
    putstr("rAll\n");
    return (1);
}