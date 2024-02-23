/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:43:15 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/23 15:22:51 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bin_to_char(char *bin)
{
	char	c;
	int		dec;
	int		i;

	c = 0;
	dec = 128;
	i = 0;
	while (bin[i])
	{
		c += (bin[i] - '0') * dec;
		dec /= 2;
		i++;
	}
	ft_printf("%c", c);
}

void	sig_action(int sig)
{
	char	bin[8];
	static int	i = 0;
	
	if (sig == SIGUSR1)
	{
		bin[i] = '1';
		i++;
	}
	else if (sig == SIGUSR2)
	{
		bin[i] = '0';
		i++;
	}
	if (i == 8)
	{
		bin[i] = '\0';
		i = 0;
		bin_to_char(bin);
	}
}

int	main(void)
{
	ft_printf("server PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, sig_action);
		signal(SIGUSR2, sig_action);
	}
	return (0);
}