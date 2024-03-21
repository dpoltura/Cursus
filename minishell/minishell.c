/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:52:43 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/21 15:03:44 by dpoltura         ###   ########.fr       */
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
	ft_readline(&data);
	split_input(&data);

	// ============= TESTS =============
		
	print_split_input(&data);
	print_env_split_var(&data);
	free_data(&data);
	return (0);
}
