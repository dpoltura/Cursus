/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:58:46 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/16 13:20:00 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	if_back_directory(char **split_input)
{
	int	i;
	char	cwd[1024];

	i = 1;
	while (ft_strcmp(split_input[i], ".."))
	{
		chdir("..");
		getcwd(cwd, sizeof(cwd));
		setenv("PWD", cwd, 1);
		i++;
		while (split_input[i] && ft_strcmp(split_input[i], "/"))
			i++;
		if (!split_input[i])
			return (1);
		else if (!ft_strcmp(split_input[i], ".."))
			break ;
	} 
	return (0);
}

static int	if_wave(char **split_input)
{
	int	i;
	char	cwd[1024];

	i = 1;
	if (ft_strcmp(split_input[i], "~"))
	{
		chdir(getenv("HOME"));
		getcwd(cwd, sizeof(cwd));
		setenv("PWD", cwd, 1);
		i++;
		while (split_input[i] && ft_strcmp(split_input[i], "/"))
			i++;
		if (!split_input[i])
			return (1);
	}
	return (0);
}

static int	if_front_directory(char **split_input)
{
	int	i;
	char	*dir;
	char	cwd[1024];

	i = 1;
	if (access(split_input[i], R_OK) == 0)
	{
		dir = ft_strdup(getenv("PWD"));
		dir = ft_strjoin(dir, "/");
		dir = ft_strjoin(dir, split_input[1]);
		chdir(dir);
		free(dir);
		getcwd(cwd, sizeof(cwd));
		setenv("PWD", cwd, 1);
		return (1);
	}
	return (0);
}

int	if_directory(char **split_input)
{
	if (ft_strcmp(split_input[0], "cd"))
	{
		if_wave(split_input);
		if (!if_back_directory(split_input))
		{
			if (!if_front_directory(split_input))
			{
				
			}
		}
		return (1);
	}
	return (0);
}
