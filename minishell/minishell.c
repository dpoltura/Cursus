/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:52:43 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/21 13:41:10 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	if (argc != 1 || !argv || !env)
		return (1);
	init_data(&data);
	data->input = readline("test > ");
	split_input(&data);
	print_split_input(&data);
	ft_getenv("PATH", &data);
	ft_getenv("USER", &data);
	ft_getenv("PAGER", &data);
	print_env_split_var(&data);
	free_data(&data);
	return (0);
}
