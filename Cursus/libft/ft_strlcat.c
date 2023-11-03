/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:37:54 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/03 12:35:57 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int	j;

	i = 0;
	j = 0;
	if (size != 0)
	{
		while (dst[i] != '\0')
			i++;
		while (src[j] != '\0' && i < size - 1)
		{
			dst [i] = src [j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(dst) + ft_strlen(src));
}
