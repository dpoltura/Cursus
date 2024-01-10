/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:02:28 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/10 11:44:32 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

struct t_list {
    int nbr;
    struct t_list *next;
};

void	error(void);
int     is_digit(char *argv);
int     check(char **argv);
void	putstr(char *str);
void	putnbr(int nbr);
int     ft_atoi(const char *nptr);
void	free_list(struct t_list **stack);
void    init(struct t_list **stack, char **argv);
int	swap(struct t_list **stack);
int    swap_all(struct t_list *stack_a, struct t_list *stack_b);
int	push_a(struct t_list **stack_b, struct t_list **stack_a);
int	push_b(struct t_list **stack_a, struct t_list **stack_b);
int    rotate(struct t_list **stack);
int    rotate_all(struct t_list **stack_a, struct t_list **stack_b);
int    reverse_rotate(struct t_list **stack);
int    reverse_rotate_all(struct t_list **stack_a, struct t_list **stack_b);
int	pivot_three(struct t_list **stack);
int	pivot_two(struct t_list **stack);

#endif
