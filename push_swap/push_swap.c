/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:02:15 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/14 00:25:43 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || !check(argv))
		error();
	init(&stack_a, argv);
	radix_sort(&stack_a, &stack_b);
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}