/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:18:05 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/02 14:57:59 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*scpy;

	i = 0;
	scpy = s;
	while (scpy[i] != c)
	{
		i++;
		if (i == n)
			return (NULL);
	}
	return ((void *)s + i);
}
