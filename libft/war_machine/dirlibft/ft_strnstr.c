/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:58:47 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/02 10:28:35 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (little[i] != '\0')
		i++;
	if (i == 0)
		return ((char *)big);
	i = 0;
	while (i < len)
	{
		while (little[j] == big[i])
		{
			i++;
			j++;
			if (i <= len && little[j] == '\0')
				return ((char *)big + (i - j));
		}
		i++;
	}
	return (NULL);
}
