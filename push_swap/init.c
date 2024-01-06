/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:11:58 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/06 11:54:17 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(struct t_list **stack, char *argv)
{
	struct t_list *new_list;
	struct t_list *tmp;

	new_list = (struct t_list *)malloc(sizeof(struct t_list));
	if (!new_list)
	{
		putstr("Error\n");
		return ;
	}
	new_list->nbr = ft_atoi(argv);
	new_list->next = NULL;
	new_list->prev = NULL;
	if (*stack == NULL)
        *stack = new_list;
	else 
	{
		tmp = *stack;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new_list;
    }
}

void	init_a(struct t_list **stack_a, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		init(stack_a, argv[i]);
		i++;
	}
}

void	init_prev(struct t_list **stack)
{
	struct t_list	*prev;
	struct t_list	*current;

	current = (*stack);
	while (current)
	{	
		prev = current;
		if (!current->next)
			break ;
		current = current->next;
		current->prev = prev;
	}
	while (current)
	{
		if (!current->prev)
			break ;
		current = current->prev;
	}
	(*stack) = current;
}
