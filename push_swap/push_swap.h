/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:02:28 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/08 13:45:45 by dpoltura         ###   ########.fr       */
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
void	swap(struct t_list **stack);
void    swap_all(struct t_list *stack_a, struct t_list *stack_b);
void	push_a(struct t_list **stack_b, struct t_list **stack_a);
void	push_b(struct t_list **stack_a, struct t_list **stack_b);
void    rotate(struct t_list **stack);
void    rotate_all(struct t_list **stack_a, struct t_list **stack_b);
void    reverse_rotate(struct t_list **stack);
void    reverse_rotate_all(struct t_list **stack_a, struct t_list **stack_b);

#endif
