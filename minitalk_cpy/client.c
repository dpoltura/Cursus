/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:42:53 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/29 16:51:13 by dpoltura         ###   ########.fr       */
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

void	send_sig(char **argv, int bit, int i)
{
	if (((argv[2][i] >> bit) & 1) == 1)
	{
		if (kill(ft_atoi(argv[1]), SIGUSR1))
		{
			ft_printf("Message not received\n");
			exit(1);
		}
	}
	else
	{
		if (kill(ft_atoi(argv[1]), SIGUSR2))
		{
			ft_printf("Message not received\n");
			exit(1);
		}
	}
	usleep(200);
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
			send_sig(argv, bit, i);
			bit--;
		}
		bit = 7;
		i++;
		if (!argv[2][i])
		{
			while (bit >= 0)
			{
				send_sig(argv, bit, i);
				bit--;
			}
		}
	}
}

int	check_pid(char **argv)
{
	if (ft_atoi(argv[1]) > 0)
		return (1);
	return (0);
}

void	sig_confirm(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Message Received\n");
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !check_pid(argv))
		return (1);
	signal(SIGUSR1, sig_confirm);
	send_char(argv);
	return (0);
}
