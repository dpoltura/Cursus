/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:01:44 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/08 12:21:47 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(struct t_list **stack_a, struct t_list **stack_b)
{
    struct t_list   *new_a;
    struct t_list   *new_b;

    if (!(*stack_a))
        return ;
    new_b = (struct t_list *)malloc(sizeof(struct t_list));
    if (!new_b)
        error();
    new_b->nbr = (*stack_a)->nbr;
    new_b->next = *stack_b;
    *stack_b = new_b;
    new_a = (*stack_a)->next;
    free(*stack_a);
    *stack_a = new_a;
}

void	push_a(struct t_list **stack_b, struct t_list **stack_a)
{
    struct t_list   *new_a;
    struct t_list   *new_b;

    if (!(*stack_b))
        return ;
    new_a = (struct t_list *)malloc(sizeof(struct t_list));
    if (!new_a)
        error();
    new_a->nbr = (*stack_b)->nbr;
    new_a->next = *stack_a;
    *stack_a = new_a;
    new_b = (*stack_b)->next;
    free(*stack_b);
    *stack_b = new_b;
}