/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:43:15 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/01 10:28:46 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_count = 0;

void	bin_to_char(char *bin)
{
	char		c;
	int			dec;
	int			i;

	c = 0;
	dec = 128;
	i = 0;
	while (bin[i])
	{
		c += (bin[i] - '0') * dec;
		dec /= 2;
		i++;
	}
	if (c == '\0')
	{
		ft_printf("\n\n");
		g_count = 0;
	}
	if (g_count == 0)
		ft_printf("\033[0;32mMessage > \033[0m");
	ft_printf("%c", c);
	g_count = 1;
}

void	sig_action(int sig)
{
	static char	bin[8];
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

void	print_banner(void)
{
	ft_printf("\033[0;32m");
	ft_printf("\n░▒▓██████████████▓▒░░▒▓█▓▒░▒▓███████▓▒░░▒▓█▓▒░");
	ft_printf("▒▓████████▓▒░▒▓██████▓▒░░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░\n");
	ft_printf("░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░ ");
	ft_printf(" ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░\n");
	ft_printf("░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░");
	ft_printf("  ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░\n");
	ft_printf("░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░");
	ft_printf("  ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░\n");
	ft_printf("░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░");
	ft_printf("  ░▒▓█▓▒░  ░▒▓████████▓▒░▒▓█▓▒░      ░▒▓███████▓▒░\n");
	ft_printf("░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░");
	ft_printf("  ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░\n");
	ft_printf("░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░");
	ft_printf("  ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░\n");
	ft_printf("░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░");
	ft_printf("  ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░\n\n");
	ft_printf("\033[0m");
}

int	main(void)
{
	print_banner();
	ft_printf("\033[0;32mServer PID: \033[0m%d\n\n", getpid());
	while (1)
	{
		signal(SIGUSR1, sig_action);
		signal(SIGUSR2, sig_action);
	}
	return (0);
}