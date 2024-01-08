/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:02:15 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/08 13:43:59 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display(struct t_list *stack_a, struct t_list *stack_b)
{
    while (stack_a) 
	{
        putnbr(stack_a->nbr);
		putstr(" | ");
        stack_a = stack_a->next;
    }
	putstr("END OF STACK 'A'\n");
	while (stack_b) 
	{
        putnbr(stack_b->nbr);
		putstr(" | ");
        stack_b = stack_b->next;
    }
	putstr("END OF STACK 'B'\n");
}

void	error(void)
{
	putstr("Error\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	struct t_list *stack_a;
	struct t_list *stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || !check(argv))
		error();
	init(&stack_a, argv);
	
	display(stack_a, stack_b);
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}