/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:37:54 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/06 09:36:01 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	full_len;

	if (size == 0 && dst == NULL)
		return (0);
	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	full_len = i + ft_strlen(src);
	if (size != 0)
	{
		i = ft_strlen(dst);
		while (src[j] != '\0' && i < size - 1)
		{
			dst [i] = src [j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (full_len);
}
