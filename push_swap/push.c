/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:50:26 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/06 08:50:41 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_down(struct t_list **stack)
{
	struct t_list	*new_first;

	new_first = (struct t_list *)malloc(sizeof(struct t_list));
	if (!new_first)
	{
		putstr("Error\n");
		return ;
	}
	new_first->nbr = 0;
	new_first->next = *stack;
	new_first->prev = NULL;
	*stack = new_first;
}
