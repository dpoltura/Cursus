/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:02:28 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/05 14:33:49 by dpoltura         ###   ########.fr       */
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

void	init(struct t_list **stack, char *argv);
void	init_a(struct t_list **stack_a, char **argv);
void	putstr(char *str);
void	putnbr(int nbr);
int	ft_atoi(const char *nptr);
int	is_digit(char *argv);
int	check(char **argv);
void	swap(struct t_list **stack);
void    swap_all(struct t_list **stack_a, struct t_list **stack_b);

#endif
