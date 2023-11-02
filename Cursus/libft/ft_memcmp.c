/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:32:15 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/02 15:26:27 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*s1_cpy;
	const char	*s2_cpy;

	i = 0;
	s1_cpy = s1;
	s2_cpy = s2;
	while (i < n)
	{
		while (s1_cpy[i] == s2_cpy[i])
		{
			if (s1_cpy[i] == '\0' || s2_cpy[i] == '\0')
				return (0);
			i++;
		}
		if ((s1_cpy[i] < s2_cpy[i] || s1_cpy[i] > s2_cpy[i]) && i < n)
			return (s1_cpy[i] - s2_cpy[i]);
	}
	return (0);
}
