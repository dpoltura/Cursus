/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:02:28 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/08 16:13:17 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include <stdio.h>

typedef struct  s_list
{
    int nbr;
    int index;
    struct s_list *next;
    struct s_list *prev;
}   t_list;

void	error(void);
int     is_digit(char *argv);
int     check(char **argv);
void	putstr(char *str);
void	putnbr(int nbr);
int     ft_atoi(const char *nptr);
void	free_list(t_list **stack);
void    init(t_list **stack, char **argv);
int	swap(t_list **stack, int choice);
int    swap_all(t_list **stack_a, t_list **stack_b);
int	push_a(t_list **stack_b, t_list **stack_a);
int	push_b(t_list **stack_a, t_list **stack_b);
int    rotate(t_list **stack, int choice);
int    rotate_all(t_list **stack_a, t_list **stack_b);
int    reverse_rotate(t_list **stack, int choice);
int    reverse_rotate_all(t_list **stack_a, t_list **stack_b);

// ALGO :
int		list_size(t_list **stack);
void	index_list(t_list **stack, int index);
int is_sorted_test(t_list *head);
void radix_sort(t_list *a, t_list *b);
void		algo(t_list **stack_a, int index);

#endif
