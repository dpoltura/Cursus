/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:52:15 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/14 12:00:25 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <term.h>

char    **ft_split(char const *s, char c);
size_t  ft_strlen(const char *s);
void	free_split(char **split);
char    *ft_strjoin(const char *s1, const char *s2);
char	*check_path(char **split_path, char *input);

#endif
