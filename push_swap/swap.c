/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:09:21 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/05 14:33:25 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(struct t_list **stack)
{
	struct t_list *tmp;
    int tmp_bis;
    int tmp_ter;

    if (!(*stack) || !((*stack)->next))
        return ;
    tmp = (*stack)->next;
    tmp_bis = (*stack)->nbr;
	tmp_ter = tmp->nbr;
    (*stack)->nbr = tmp_ter;
    tmp->nbr = tmp_bis;
    (*stack)->next = tmp;
}

void    swap_all(struct t_list **stack_a, struct t_list **stack_b)
{
    swap(stack_a);
    swap(stack_b);
}
