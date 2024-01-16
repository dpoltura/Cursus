/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:25:43 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/16 15:44:38 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    sort_smaller(t_list **stack)
{
    t_list  *current;
    t_list  *next;
    int index;

    current = *stack;
    next = (*stack)->next;
    while (next)
    {
        if (current->nbr < next->nbr)
            index = current->index;
        else
        {
            current = next;
            index = current->index;
        }
        next = next->next;
    }
    return (index);
}

void	r_or_rr(t_list	**stack_a, t_list **stack_b)
{
	int	index;
	int	i;
	
	i = 1;
	while ((*stack_a)->next)
	{
		if ((index = sort_smaller(stack_a)) < (index_list(stack_a) / 2))
		{
			while ((*stack_a)->index != index)
			{
				rotate(stack_a, 1);
				printf("%d\n", i);
				i++;
			}
			push_b(stack_a, stack_b);
			printf("%d\n", i);
			i++;
			index_list(stack_a);
		}
		else
		{
			while ((*stack_a)->index != index)
			{
				reverse_rotate(stack_a, 1);
				printf("%d\n", i);
				i++;
			}
			push_b(stack_a, stack_b);
			printf("%d\n", i);
			i++;
			index_list(stack_a);
		}
	}
	while (*stack_b)
	{
		push_a(stack_b, stack_a);
		printf("%d\n", i);
		i++;
	}
}
