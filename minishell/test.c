/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:46:44 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/21 13:57:25 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_split_input(t_data **data)
{
	t_split	*cursor;

	cursor = (*data)->split_input;
	printf("\n\n");
	while (cursor)
	{
		printf("input = %s\n", cursor->content);
		cursor = cursor->next;
	}
	printf("\n\n");
}

void	print_env_split_var(t_data **data)
{
	t_env	*env_vars;
	t_split	*var_split_content;

	env_vars = (*data)->env_vars;
	var_split_content = (*data)->env_vars->var_split_content;
	while (env_vars)
	{
		printf("var = %s\n", env_vars->var);
		if (env_vars->var_content)
			printf("content = %s\n", env_vars->var_content);
		while (var_split_content)
		{
			printf("split_content = %s\n", var_split_content->content);
			var_split_content = var_split_content->next;
		}
		printf("\n\n");
		env_vars = env_vars->next;
		if (env_vars)
			var_split_content = env_vars->var_split_content;
	}
}
