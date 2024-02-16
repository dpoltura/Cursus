/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:15:34 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/16 14:54:44 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	error(t_list **stack_a, t_bool *boolean, char **argv)
{
	free_list(stack_a);
	if (boolean->boolean == 0)
		free_argv(argv);
	free(boolean);
	putstr("Error\n");
	exit(EXIT_FAILURE);
}

int	is_digit(char *argv)
{
	int	nbr;
	
	nbr = ft_atoi(argv);
	if (nbr == (0))
		return (0);
	return (nbr);
}

int	check(char **argv, t_bool *boolean)
{
	int	i;

	if (boolean->boolean == 0)
		i = 0;
	else
		i = 1;
	while (argv[i])
	{
		if (!is_digit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}