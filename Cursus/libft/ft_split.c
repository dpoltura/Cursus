/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:29:30 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/06 16:28:21 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	ft_count_word(const char *s, char c)
{
	int	i;
	int	n_word;

	i = 0;
	n_word = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		while (s[i] == c)
                        i++;
		n_word++;
	}
	return (n_word);
}

int	main(void)
{
	printf("%d\n", ft_count_word("wefwefwe|||||||||wefwef", '|'));
	return (0);
}
