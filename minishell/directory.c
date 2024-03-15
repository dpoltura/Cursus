/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:58:46 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/15 13:24:33 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	if_back_directory(char **split_input)
{
	int	i;
	char	dir[1024];

	i = 1;
	while (split_input[i])
	{
		if (ft_strcmp(split_input[i], ".."))
			chdir("..");
		getcwd(dir, sizeof(dir));
		setenv("PWD", dir, 1);
		if (split_input[i] && ft_strcmp(split_input[i], "/"))
			i++;
		if (!split_input[i])
			return (1);
		i++;
	} 
	return (0);
}

int	if_directory(char **split_input)
{
	int	i;
	char	*dir;

	i = 1;
	if (ft_strcmp(split_input[0], "cd"))
	{
		if (!if_back_directory(split_input))
		{
			if (access(split_input[i], R_OK) == 0)
			{
				dir = ft_strdup(getenv("PWD"));
				dir = ft_strjoin(dir, "/");
				dir = ft_strjoin(dir, split_input[1]);
				chdir(dir);
				free(dir);
			}
		}
		return (1);
	}
	return (0);
}
