/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:43:15 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/27 16:05:02 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_line = NULL;

void	bin_to_char(char *bin)
{
	char		c[2];
	int			dec;
	int			i;

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
		ft_printf("%s\n", g_line);
		free(g_line);
		g_line = NULL;
	}
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
	ft_printf("server PID: %d\n\n", getpid());
	while (1)
	{
		signal(SIGUSR1, sig_action);
		signal(SIGUSR2, sig_action);
	}
	return (0);
}
