/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:52:43 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/14 12:29:55 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	argc = 0;
	
	char	*input;
	char	*path;
	char	**split_path;
	char	*full_path;

	while (1)
	{
		input = readline("$ ");
		if (!input)
			return (1);
		break ;
	}
	path = getenv("PATH");
	split_path = ft_split(path, ':');
	full_path = check_path(split_path, input);
	execve(full_path, argv, env);
	free(input);
	free_split(split_path);
	free(full_path);
	return (0);
}
