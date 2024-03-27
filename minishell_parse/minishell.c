/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:20:24 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/27 15:49:08 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	(void) argc;
	(void) **argv;
	(void) **env;

	t_split	*split;
	char	*line;

	split = malloc(sizeof(t_split));
	split->content = NULL;
	split->next = NULL;
	line = readline("> ");
	split_line(split, line);
	while (split)
	{
		printf("%s\n", split->content);
		split = split->next;
	}
	return (0);
}
