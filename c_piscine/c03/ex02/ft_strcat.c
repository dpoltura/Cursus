/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:04:57 by dpoltura          #+#    #+#             */
/*   Updated: 2023/09/27 16:40:04 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest [i] != '\0')
	{
		i++;
	}
	while (src [j] != '\0')
	{
		dest [i] = src [j];
		i++;
		j++;
	}
	dest [i] = '\0';
	return (dest);
}
