/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:52:15 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/16 11:35:25 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// ============= LIBRAIRIES =============

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <term.h>
# include <sys/wait.h>

// ============= COLORS =============

# define BOLD "\033[1m"
# define RESET "\033[0m"
# define RED "\033[38;5;196m"
# define GREEN "\033[38;5;46m"
# define YELLOW "\033[38;5;226m"
# define BLUE "\033[38;5;21m"

// ============= FUNCTIONS =============

char    **ft_split(char const *s, char c);
size_t  ft_strlen(const char *s);
void	free_split(char **split);
char    *ft_strjoin(const char *s1, const char *s2);
char	*check_path(char **split_path, char *input);
char    *ft_strdup(const char *s);
int	ft_strcmp(char *s1, char *s2);
int	if_directory(char **split_input);

#endif
