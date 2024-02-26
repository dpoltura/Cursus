/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:43:15 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/26 13:04:11 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char *line = NULL;

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*res;
	size_t	total;

	total = nmemb * size;
	if (!total)
		return (malloc(1));
	if (nmemb > INT_MAX || size > INT_MAX)
		return (NULL);
	if (!nmemb || !size)
		return (NULL);
	res = (char *)malloc(total);
	if (!res)
		return (NULL);
	ft_memset(res, 0, total);
	return ((void *)res);
}

void	bin_to_char(char *bin)
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
	if (!line)
		line = ft_calloc(1, 1);
	line = ft_strjoin_serv(line, c);
	if (c[0] == '\n')
	{
		ft_printf("%s", line);
		free(line);
		line = NULL;
	}
}

void	sig_action(int sig)
{
	static char		bin[8];
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
	ft_printf("\033[0;32m");
	ft_printf("\n░▒▓██████████████▓▒░░▒▓█▓▒░▒▓███████▓▒░░▒▓█▓▒░▒▓████████▓▒░▒▓██████▓▒░░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░\n");
	ft_printf("░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░  ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░\n");
	ft_printf("░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░  ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░\n");
	ft_printf("░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░  ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░\n");
	ft_printf("░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░  ░▒▓█▓▒░  ░▒▓████████▓▒░▒▓█▓▒░      ░▒▓███████▓▒░\n");
	ft_printf("░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░  ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░\n");
	ft_printf("░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░  ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░\n");
	ft_printf("░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░  ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░\n\n");
	ft_printf("\033[0m");
	ft_printf("server PID: %d\n\n", getpid());
	while (1)
	{
		signal(SIGUSR1, sig_action);
		signal(SIGUSR2, sig_action);
	}
	return (0);
}
