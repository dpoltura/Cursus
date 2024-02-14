/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:02:15 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/14 18:18:42 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display(t_list **stack)
{
	t_list *current;

	current = *stack;
	while (current)
	{
		putnbr(current->nbr);
		if (current->next)
			putstr(" ");
		current = current->next;
	}
	putstr("\n");
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**split_argv(char **argv)
{
	int		i;
	int		j;
	int		k;
	char	**split_argv;
	char	**tmp;

	i = 1;
	j = 0;
	k = 0;
	split_argv = malloc(sizeof(int *) * 500);
	while (argv[i])
	{
		tmp = ft_split(argv[i], '\n');
		while (tmp[j])
		{
			split_argv[k] = ft_strdup(tmp[j]);
			k++;
			j++;
		}
		j = 0;
		i++;
	}
	return (split_argv);
}

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || !check(argv))
		error(&stack_a);
	argv = split_argv(argv);
	init(&stack_a, argv);
	check_double(&stack_a);
	algo(&stack_a, &stack_b);
	display(&stack_a);
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}