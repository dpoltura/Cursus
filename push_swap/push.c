/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:01:44 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/05 16:22:17 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(struct t_list **stack_a, struct t_list **stack_b)
{
    struct t_list   *tmp;

    tmp = (*stack_a);
    (*stack_a)->next = (*stack_b);
    (*stack_a)->next = tmp->next;
}
