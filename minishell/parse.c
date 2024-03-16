/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:03:50 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/16 12:27:51 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_path(char **split_path, char *input)
{
	int	i;
	char	*full_path;

	i = 0;
	while (split_path[i])
	{
        full_path = ft_strdup(split_path[i]);
		full_path = ft_strjoin(full_path, "/");
		full_path = ft_strjoin(full_path, input);
		if (access(full_path, F_OK) == -1)
			free(full_path);
		else if (access(full_path, F_OK) == 0)
			return (full_path);
		i++;
	}
	return (NULL);
}
