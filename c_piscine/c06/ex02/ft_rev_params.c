/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:56:44 by dpoltura          #+#    #+#             */
/*   Updated: 2023/10/03 11:18:45 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	j;
	int	i;

	j = 0;
	i = argc;
	while (i > 1)
	{
		write(1, &argv [i - 1][j], 1);
		j++;
		if (argv [i - 1][j] == '\0')
		{
			write(1, "\n", 1);
			j = 0;
			i--;
		}
	}
	return (0);
}