/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:02:15 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/05 13:26:09 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display(struct t_list *stack)
{
    struct t_list *tmp;
	
	tmp = stack;
    while (tmp != NULL) 
	{
        putnbr(tmp->nbr);
        tmp = tmp->next;
    }
}

int main(int argc, char **argv)
{
	struct t_list *stack_a;
	
	stack_a = NULL;
	if (argc < 2 || !check(argv))
	{
		putstr("Error\n");
		return (1);
	}
	init_a(&stack_a, argv);
	display(stack_a);
	free(stack_a);
	return (0);
}