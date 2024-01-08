/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:23:11 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/08 13:36:55 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    reverse_rotate(struct t_list **stack)
{
    struct t_list   *current;
    struct t_list   *last;
    struct t_list   *first;

    if (!(*stack) || !(*stack)->next)
        return ;
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
}

void    rotate(struct t_list **stack)
{
    struct t_list   *first;
    struct t_list   *current;

    if (!(*stack) || !(*stack)->next)
        return ;
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
}

void    reverse_rotate_all(struct t_list **stack_a, struct t_list **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
}

void    rotate_all(struct t_list **stack_a, struct t_list **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
}