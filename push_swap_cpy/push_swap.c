/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:02:15 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/17 13:02:47 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display(t_list *stack_a, t_list *stack_b)
{
    while (stack_a) 
	{
        putnbr(stack_a->nbr);
        stack_a = stack_a->next;
		if (stack_a)
			putstr(" ");
    }
	putstr(" / END OF STACK 'A'\n");
	while (stack_b) 
	{
        putnbr(stack_b->nbr);
        stack_b = stack_b->next;
		if (stack_b)
			putstr(" ");
    }
	putstr(" / END OF STACK 'B'\n");
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
	printf("%d\n", algo(&stack_a, &stack_b, 1));
	display(stack_a, stack_b);
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}