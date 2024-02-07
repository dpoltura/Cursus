/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:15:34 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/16 10:39:58 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
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

int	check(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!is_digit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}