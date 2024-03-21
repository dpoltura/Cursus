/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:46:44 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/21 17:11:59 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_split_input(t_data **data)
{
	t_split	*cursor;

	cursor = (*data)->split_input;
	printf(BOLD GREEN "INPUT:\n" RESET);
	while (cursor)
	{
		printf("%s\n", cursor->content);
		cursor = cursor->next;
	}
	printf("\n");
}

void	print_env_split_var(t_data **data)
{
	t_env	*env_vars;
	t_split	*var_split_content;

	env_vars = (*data)->env_vars;
	var_split_content = (*data)->env_vars->var_split_content;
	while (env_vars)
	{
		printf(BOLD GREEN "VAR:\n" RESET "%s\n", env_vars->var);
		if (env_vars->var_content)
			printf(BOLD YELLOW "CONTENT:\n" RESET "%s\n", env_vars->var_content);
		printf(BOLD RED "SPLIT CONTENT:\n" RESET);
		while (var_split_content)
		{
			printf("%s\n", var_split_content->content);
			var_split_content = var_split_content->next;
		}
		printf("\n");
		env_vars = env_vars->next;
		if (env_vars)
			var_split_content = env_vars->var_split_content;
	}
}
