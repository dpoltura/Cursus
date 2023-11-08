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

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	alloc_value;

	if (count >= INT_MAX || size >= INT_MAX \
		|| (int)count == INT_MIN \
		|| (int)size == INT_MIN \
		|| (count < 0 && size != 0) \
		|| (count != 0 && size < 0))
		return (NULL);
	if ((!count && size < 0) \
		|| (count < 0 && !size))
	{
		res = (char *)malloc(1);
		if (!res)
			return (NULL);
		return ((void *)res);
	}
	alloc_value = count * size;
	res = (char *)malloc(alloc_value);
	if (!res)
		return (NULL);
	ft_memset(res, 0, alloc_value);
	return ((void *)res);
}
