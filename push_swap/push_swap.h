/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:02:28 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/16 15:03:17 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_bool
{
    int boolean;
}   t_bool;

typedef struct  s_list
{
    int nbr;
    int index;
    struct s_list *next;
    struct s_list *prev;
}   t_list;

void	error(t_list **stack_a, t_bool *boolean, char **argv);
int     is_digit(char *argv);
int     check(char **argv, t_bool *boolean);
void	putstr(char *str);
void	putnbr(int nbr);
int     ft_atoi(const char *nptr);
void	free_list(t_list **stack);
void    init(t_list **stack, char **argv, t_bool *boolean);
int	swap(t_list **stack, int choice);
int    swap_all(t_list **stack_a, t_list **stack_b);
int	push_a(t_list **stack_b, t_list **stack_a);
int	push_b(t_list **stack_a, t_list **stack_b);
int    rotate(t_list **stack, int choice);
int    rotate_all(t_list **stack_a, t_list **stack_b);
int    reverse_rotate(t_list **stack, int choice);
int    reverse_rotate_all(t_list **stack_a, t_list **stack_b);
int		list_size(t_list **stack);
void	index_list(t_list **stack, int index);
int		check_if_sorted(t_list **stack);
void	sort_two(t_list **stack_a, int choice);
void	sort_three(t_list **stack_a);
void	sort_five(t_list **stack_a, t_list **stack_b);
void    radix_sort(t_list **stack_a, t_list **stack_b);
void	algo(t_list **stack_a, t_list **stack_b);
void	check_double(t_list **stack_a, t_bool *boolean, char **argv);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
void	free_argv(char **argv);

#endif