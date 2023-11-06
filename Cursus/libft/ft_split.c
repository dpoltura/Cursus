/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:29:30 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/06 11:44:25 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	ft_count_word(const char *s, char c)
{
	int	i;
	int	count_word;

	i = 0;
	count_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			i++;
		else
		{
			count_word++;
			i++;
		}
	}
	return (count_word);
}

int	ft_word_len(const char *s, char c, int start)
{
	int	i;

	i = 0;
	while (s[start] != c)
	{
		start++;
		i++;
	}
	return (i);
}

void	*ft_alloc_split(char **split, const char *s, char c)
{
	int	i;
	int	start;
	int	count_word;
	int	word_len;

	i = 0;
	start = 0;
	count_word = ft_count_word(s, c);
	word_len = ft_word_len(s, c, start);
	while (i < count_word)
	{
		split[i] = malloc(sizeof(char *) * (word_len + 1));
		if (split[i] == NULL)
			return (NULL);
		start += word_len;
		i++;
	}
	return (0);
}

char	**ft_split(const char *s, char c)
{
	int	i;
	int	j;
	int	k;
	char	**split;
	int	count_word;

	i = 0;
	j = 0;
	k = 0;
	count_word = ft_count_word(s, c);
	split = malloc(sizeof(char **) * (count_word + 1));
	if (split == NULL)
		return (NULL);
	ft_alloc_split(split, s, c);
	while (count_word > 0)
	{
		if (s[i] == c)
		{
			count_word--;
			i++;
			j++;
			k = 0;
		}
		if (s[i] == '\0' || i > 11)
			return (split);
		split[j][k] = s[i];
		i++;
		k++;
	}
	return (split);
}

int	main(void)
{
	char	**split;

	split = ft_split("Hello|World|wefwefwefwfe|wefwef|dwefwef", '|');
	printf("%s\n%s\n%s\n", split[0], split[1], split[2]);
	free(split);
	return (0);
}
