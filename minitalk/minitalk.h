/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:55:49 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/27 16:09:25 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <signal.h>
# include <stdlib.h>

void	print_banner(void);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);
void	send_char(char **argv);
char	*ft_strjoin(char *s1, const char *s2);
void	bin_to_char(char *bin);
void	sig_action(int sig);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	send_sig(char **argv, int bit, int i);
int		check_pid(char **argv);

#endif