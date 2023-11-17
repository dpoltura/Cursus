/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:34:48 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/17 13:19:02 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_reverse(char *res)
{
	char	*tmp;
	int	i;

	i = ft_strlen(res);
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	while (i > 0)
	{
		i--;
		*tmp = *(res + i);
		tmp++;
	}
	*tmp = 0;
	res = tmp - ft_strlen(res);
	return (res);
}

void	ft_putnbr_base_fd(unsigned long n, char *base, int fd)
{
	char	*res;
	int	i;

	i = 0;
	res = malloc(sizeof(char) * 255);
	if (!res)
		return ;
	while (n)
	{
		*(res + i) = *(base + (n % ft_strlen(base)));
		n = n / ft_strlen(base);
		i++;
	}
	*(res + i) = 0;
	res = ft_reverse(res);
	ft_putstr_fd("0x", fd);
	ft_putstr_fd(res, fd);
	free(res);
}