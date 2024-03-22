/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:52:43 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/22 14:25:34 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	if (argc != 1 || !argv || !env)
		return (1);
	init_data(&data);
	ft_getenv(&data);
	while (1)
	{
		ft_readline(&data);
		split_input(&data);
		/* ============= TESTS FUNCTIONS ============= */
		print_input(&data);
		print_env_split_var(&data);
		// ===========================================
		ft_execve(&data, argv, env);
	}
	free_data(&data);
	return (0);
}
