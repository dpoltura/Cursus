/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:51:30 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/02 16:26:33 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*alloc;
	size_t	i;

	i = 0;
	if ((alloc = malloc(sizeof(size) * nmemb)) == NULL)
		return (NULL);
	while (i < nmemb)
	{
		alloc[i] = 0;
		i++;
	}
	return ((void *)alloc);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*test = ft_calloc(33, 1);
	printf("%s\n", test);
	free(test);
	return (0);
}
*/
