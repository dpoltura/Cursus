/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:37:54 by dpoltura          #+#    #+#             */
/*   Updated: 2023/10/31 15:17:55 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (dst[i] != '\0')
		i++;
	k = i;
	while (src[j] != '\0' && j < size - k + 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (i);
}
