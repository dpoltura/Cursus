/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:58:46 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/15 11:41:14 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	if_directory(char **split_input)
{
	char	*dir;

	if (ft_strcmp(split_input[0], "cd"))
	{
		if (ft_strcmp(split_input[1], ".."))
			chdir("..");
		else if (access(split_input[1], R_OK) == 0)
		{
			dir = ft_strdup(getenv("OLDPWD"));
			dir = ft_strjoin(dir, "/");
			dir = ft_strjoin(dir, split_input[1]);
			chdir(dir);
			free(dir);
		}
		return (1);
	}
	return (0);
}
