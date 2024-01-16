/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:02:15 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/16 09:58:28 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display(t_list *stack_a, t_list *stack_b)
{
	t_list	*prev;
	
    while (stack_a) 
	{
		putstr("nbr : ");
        putnbr(stack_a->nbr);
		putstr(" | index : ");
		putnbr(stack_a->index);
		putstr(" | prev nbr : ");
		prev = stack_a->prev;
		if (prev)
		{
			putnbr(prev->nbr);
			putstr(" | prev index : ");
			putnbr(prev->index);
		}
		putstr(" | ");
        stack_a = stack_a->next;
    }
	putstr("END OF STACK 'A'\n");
	while (stack_b) 
	{
        putstr("nbr : ");
        putnbr(stack_b->nbr);
		putstr(" | index : ");
		putnbr(stack_b->index);
		putstr(" | prev nbr : ");
		prev = stack_b->prev;
		if (prev)
		{
			putnbr(prev->nbr);
			putstr(" | prev index : ");
			putnbr(prev->index);
		}
		putstr(" | ");
        stack_b = stack_b->next;
    }
	putstr("END OF STACK 'B'\n");
}

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || !check(argv))
		error();
	init(&stack_a, argv);
	swap(&stack_a, 1);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	rotate_all(&stack_a, &stack_b);
	reverse_rotate_all(&stack_a, &stack_b);
	swap(&stack_a, 1);
	push_a(&stack_b, &stack_a);
	push_a(&stack_b, &stack_a);
	push_a(&stack_b, &stack_a);
	display(stack_a, stack_b);
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}