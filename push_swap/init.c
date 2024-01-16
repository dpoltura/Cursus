/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:11:58 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/16 11:31:23 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_list **stack, char **argv)
{
	t_list	*first;
	t_list	*prev;
	int	i;

	if (*stack)
		error();
	*stack = (t_list *)malloc(sizeof(t_list));
	if (!(*stack))
		error();
	first = *stack;
	prev = NULL;
	i = 1;
	while (argv[i])
	{
		(*stack)->nbr = ft_atoi(argv[i]);
		(*stack)->index = i;
		if (argv[i + 1])
		{
			(*stack)->next = (t_list *)malloc(sizeof(t_list));
			if (!(*stack)->next)
				error();
		}
		(*stack)->prev = prev;
		prev = *stack;
		if (argv[i + 1])
			*stack = (*stack)->next;
		i++;
	}
	(*stack)->next = NULL;
	*stack = first;
}
