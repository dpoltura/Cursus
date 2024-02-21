/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:11:58 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/20 15:18:21 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	atoi_argv(t_list **stack, char **argv, t_bool *boolean, int i)
{
	t_list	*prev;

	prev = NULL;
	while (argv[i])
	{
		(*stack)->nbr = ft_atoi(argv[i], stack, boolean, argv);
		(*stack)->index = 0;
		if (argv[i + 1])
		{
			(*stack)->next = (t_list *)malloc(sizeof(t_list));
			if (!(*stack)->next)
				error(stack, boolean, argv);
		}
		(*stack)->prev = prev;
		prev = *stack;
		if (argv[i + 1])
			*stack = (*stack)->next;
		i++;
	}
}

void	init(t_list **stack, char **argv, t_bool *boolean)
{
	t_list	*first;
	int		i;

	if (*stack)
		error(stack, boolean, argv);
	*stack = (t_list *)malloc(sizeof(t_list));
	if (!(*stack))
		error(stack, boolean, argv);
	first = *stack;
	if (boolean->boolean == 0)
		i = 0;
	else
		i = 1;
	atoi_argv(stack, argv, boolean, i);
	(*stack)->next = NULL;
	*stack = first;
}
