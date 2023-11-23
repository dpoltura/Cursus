/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:54:19 by dpoltura          #+#    #+#             */
/*   Updated: 2023/10/31 14:48:09 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 97 && c <= 122) || c == -1)
		return (1);
	if ((c >= 65 && c <= 90) || c == -1)
		return (1);
	if ((c >= 48 && c <= 57) || c == -1)
		return (1);
	return (0);
}