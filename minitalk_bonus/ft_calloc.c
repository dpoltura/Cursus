/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:37:43 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/29 23:51:24 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*res;
	size_t	total;

	total = nmemb * size;
	if (!total)
		return (malloc(1));
	if (nmemb > INT_MAX || size > INT_MAX)
		return (NULL);
	if (!nmemb || !size)
		return (NULL);
	res = (char *)malloc(total);
	if (!res)
		return (NULL);
	ft_memset(res, 0, total);
	return ((void *)res);
}
