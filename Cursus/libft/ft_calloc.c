/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:51:30 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/06 09:32:46 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*alloc;
	size_t	i;

	i = 0;
	alloc = malloc(size * nmemb);
	if (alloc == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		alloc[i] = 0;
		i++;
	}
	return ((void *)alloc);
}
