/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:43:15 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/01 00:06:26 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_line = NULL;

void	bin_to_char(char *bin, siginfo_t *info)
{
	char	c[2];
	int		dec;
	int		i;

	c[0] = 0;
	c[1] = '\0';
	dec = 128;
	i = 0;
	while (bin[i])
	{
		c[0] += (bin[i] - '0') * dec;
		dec /= 2;
		i++;
	}
	if (!g_line)
		g_line = ft_calloc(1, 1);
	g_line = ft_strjoin(g_line, c);
	if (c[0] == '\0')
	{
		ft_printf("Message > %s\n\n", g_line);
		kill(info->si_pid, SIGUSR1);
		free(g_line);
		g_line = NULL;
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

void	sigaction_handler(int signum, siginfo_t *info, void *context)
{
	static char	bin[8];
	static int	i = 0;

	(void)context;
	if (signum == SIGUSR1)
	{
		bin[i] = '1';
		i++;
	}
	else if (signum == SIGUSR2)
	{
		bin[i] = '0';
		i++;
	}
	if (i == 8)
	{
		bin[i] = '\0';
		i = 0;
		bin_to_char(bin, info);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sigaction_handler;
	print_banner();
	ft_printf("Server PID: %d\n\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	return (0);
}
