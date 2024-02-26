/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:42:53 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/26 14:00:16 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			j = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		k = k * 10;
		k += nptr[i] - '0';
		i++;
	}
	return (k * j);
}

void	send_char(char **argv)
{
	int	bit;
	int	i;

	bit = 7;
	i = 0;
	while (argv[2][i])
	{
		while (bit >= 0)
		{
			if (((argv[2][i] >> bit) & 1) == 1)
				kill(ft_atoi(argv[1]), SIGUSR1);
			else
				kill(ft_atoi(argv[1]), SIGUSR2);
			usleep(200);
			bit--;
		}
		bit = 7;
		i++;
		if (!argv[2][i])
		{
			while (bit >= 0)
			{
				if (((argv[2][i] >> bit) & 1) == 1)
					kill(ft_atoi(argv[1]), SIGUSR1);
				else
					kill(ft_atoi(argv[1]), SIGUSR2);
				usleep(200);
				bit--;
			}
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	send_char(argv);
	return (0);
}
