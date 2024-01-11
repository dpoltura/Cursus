/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:11:58 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/08 11:16:51 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(struct t_list **stack, char **argv)
{
	struct t_list	*first;
	int	i;

	if (*stack)
		error();
	*stack = (struct t_list *)malloc(sizeof(struct t_list));
	if (!(*stack))
		error();
	i = 1;
	while (argv[i])
	{
		(*stack)->nbr = ft_atoi(argv[i]);
		if (argv[i + 1])
		{
			(*stack)->next = (struct t_list *)malloc(sizeof(struct t_list));
			if (!(*stack)->next)
				error();
		}
		if (i == 1)
			first = (*stack);
		if (argv[i + 1])
			*stack = (*stack)->next;
		i++;
	}
	(*stack)->next = NULL;
	*stack = first;
}
