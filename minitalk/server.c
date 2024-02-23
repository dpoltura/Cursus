/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:43:15 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/23 13:32:13 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_action(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("1");
	else if (sig == SIGUSR2)
		ft_printf("0");
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