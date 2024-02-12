/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:25:43 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/08 16:14:32 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		list_size(t_list **stack)
{
	t_list	*current;
	int		i;

	current = *stack;
	i = 0;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	index_list(t_list **stack, int index)
{
	t_list	*current;
	int		smallest;

	current = *stack;
	smallest = INT_MAX;
	while (current)
	{
		if (smallest >= current->nbr && current->index == 0)
			smallest = current->nbr;
		current = current->next;
	}
	current = *stack;
	while (current->nbr != smallest)
		current = current->next;
	current->index = index;
}

void		algo(t_list **stack_a, int index)
{
	int		size;
	int		i;

	size = list_size(stack_a);
	i = index;
	while (i <= size)
	{
		index_list(stack_a, i);
		i++;
	}
}

int is_sorted_test(t_list *head) {
    if (head == NULL || head->next == NULL)
        return 1;

    t_list *current = head;
    while (current->next != NULL) {
        if (current->index > current->next->index)
            return 0;
        current = current->next;
    }
    return 1;
}

void radix_sort(t_list *a, t_list *b)
{
    int            i;
    int            j;
    int            num;
    t_list    *temp;
    t_list *head;

    i = 0;
    head = a;
    while (!is_sorted_test(a))
    {
        temp = head;
        j = list_size(&head);
        while (j > 0)
        {
            num = head->index;
            temp = temp->next;
            if ((num >> i) & 1)
                rotate(&a, 1);
            else
                push_b(&a, &b);
            j--;
        }
        i++;
        while (b)
            push_a(&b, &a);
    }
}