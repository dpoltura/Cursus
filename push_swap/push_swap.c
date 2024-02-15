/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:02:15 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/15 16:57:24 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display(t_list **stack)
{
	t_list *current;

	current = *stack;
	while (current)
	{
		putnbr(current->nbr);
		if (current->next)
			putstr(" ");
		current = current->next;
	}
	putstr("\n");
}

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || !check(argv))
		error(&stack_a);
	init(&stack_a, argv);
	check_double(&stack_a);
	algo(&stack_a, &stack_b);
	display(&stack_a);
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}