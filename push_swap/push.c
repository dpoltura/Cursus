/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:50:26 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/06 09:22:37 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(struct t_list **stack_a, struct t_list **stack_b)
{
	struct t_list	*new_first;

	new_first = (struct t_list *)malloc(sizeof(struct t_list));
	if (!new_first)
	{
		putstr("Error\n");
		return ;
	}
	new_first->nbr = rm_first(stack_a);
	new_first->next = *stack_b;
	new_first->prev = NULL;
    free_list(&(*stack_b));
	*stack_b = new_first;
}

int	rm_first(struct t_list **stack)
{
	struct t_list	*tmp;
    int tmp_bis;

	tmp = (*stack)->next;
    tmp_bis = (*stack)->nbr;
    free(*stack);
    *stack = tmp;
    return (tmp_bis);
}
