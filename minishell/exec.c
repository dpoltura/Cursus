/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:15:51 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/21 18:26:55 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_path(t_data **data)
{
	char	*full_path;
	t_env	*var;
	t_split	*var_path;
	t_split	*input;

	full_path = NULL;
	var = get_var("PATH", data);
	var_path = var->var_split_content;
	input = (*data)->split_input;
	while (var_path && !full_path)
	{
		full_path = var_path->content;
		full_path = ft_strjoin(full_path, "/");
		full_path = ft_strjoin(full_path, input->content);
		if (access(full_path, R_OK))
		{
			var_path = var_path->next;
			free(full_path);
			full_path = NULL;
		}
	}
	return (full_path);
}
