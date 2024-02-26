/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:42:53 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/26 12:22:08 by dpoltura         ###   ########.fr       */
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

void	send_char(char *line, char **argv)
{
	int	bit;
	int	i;

	bit = 7;
	i = 0;
	while (line[i])
	{
		while (bit >= 0)
		{
			if (((line[i] >> bit) & 1) == 1)
				kill(ft_atoi(argv[1]), SIGUSR1);
			else
				kill(ft_atoi(argv[1]), SIGUSR2);
			usleep(200);
			bit--;
		}
		bit = 7;
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*line;

	if (argc != 3)
		return (0);
	line = ft_strjoin(argv[2], "\n");
	send_char(line, argv);
	free(line);
	return (0);
}
