/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:50:26 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/06 09:27:31 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(struct t_list **sender, struct t_list **receiver)
{
	struct t_list	*new_first;

    if (!(*sender))
        return ;
	new_first = (struct t_list *)malloc(sizeof(struct t_list));
	if (!new_first)
	{
		putstr("Error\n");
		return ;
	}
	new_first->nbr = rm_first(sender);
	new_first->next = *receiver;
	new_first->prev = NULL;
    free_list(&(*receiver));
	*receiver = new_first;
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
