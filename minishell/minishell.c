/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:52:43 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/15 09:49:38 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	argc = 0;
	argv = NULL;
	
	char	*input;
	char	**split_input;
	char	*path;
	char	**split_path;
	char	*full_path;
	pid_t	pid;

	path = getenv("PATH");
	split_path = ft_split(path, ':');
	while (1)
	{
		input = readline("$ ");
		if (!input)
			return (1);
		split_input = ft_split(input, ' ');
		free(input);
		input = split_input[0];
		full_path = check_path(split_path, input);
		pid = fork();
		if (pid == 0)
			execve(full_path, split_input, env);
		else
            waitpid(pid, NULL, 0);
		free(full_path);
		free_split(split_input);
	}
	free_split(split_path);
	return (0);
}
