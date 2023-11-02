/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:17:30 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/02 16:33:05 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int	test(void)
{
	printf("ft_isalpha : %d || isalpha : %d\n", ft_isalpha('a'), isalpha('a'));
	printf("----------------------------------------------------------------\n");
	printf("ft_isdigit : %d || isdigit : %d\n", ft_isdigit('0'), isdigit('0'));
	printf("----------------------------------------------------------------\n");
	printf("ft_isalnum : %d || isalnum : %d\n", ft_isalnum('a'), isalnum('a'));
	printf("----------------------------------------------------------------\n");
	printf("ft_isascii : %d || isascii : %d\n", ft_isascii('a'), isascii('a'));
	printf("----------------------------------------------------------------\n");
	printf("ft_isprint : %d || isprint : %d\n", ft_isprint('a'), isprint('a'));
	printf("----------------------------------------------------------------\n");
	printf("ft_strlen : %lu || strlen : %lu\n", ft_strlen("Hello World !"), strlen("Hello World !"));
	printf("----------------------------------------------------------------\n");
	int	array1[] = {1, 2, 3, 4, 5};
	int	*array2;
	int	*array3;
	void	*p1 = array1;
	array2 = ft_memset(p1, 0, 1);
	array3 = memset(p1, 0, 1);
	printf("ft_memset : %d || memset : %d\n", array2[0], array3[0]);
	printf("----------------------------------------------------------------\n");
	ft_bzero(p1, 2);
	bzero(p1, 2);
	printf("ft_bzero : %d || bzero : %d\n", array2[1], array3[1]);
	printf("----------------------------------------------------------------\n");
	const void	*p2 = array2;
	int	*array4;
	array3 = ft_memcpy(p1, p2, 3);
	array4 = memcpy(p1, p2, 3);
	printf("ft_memcpy : %d || memcpy : %d\n", array3[2], array4[2]);
	printf("----------------------------------------------------------------\n");
	array3 = ft_memmove(p1, p1, 4);
	array4 = memmove(p1, p1, 4);
	printf("ft_memmove : %d || memmove : %d (a checker)\n", array3[3], array4[3]);
	printf("----------------------------------------------------------------\n");
	//printf("ft_strlcpy : %lu || strlcpy : %lu\n", ft_strlcpy(p1, p2, 5), strlcpy(p1, p2, 5));
	//printf("ft_strlcat : %lu || strlcat : %lu\n", ft_strlcat(p1, p2, 0), strlcat(p1, p2, 0));
	printf("ft_toupper : %d || toupper : %d\n", ft_toupper('a'), toupper('a'));
	printf("----------------------------------------------------------------\n");
	printf("ft_tolower : %d || tolower : %d\n", ft_tolower('A'), tolower('A'));
	printf("----------------------------------------------------------------\n");
	printf("ft_strchr : %s || strchr : %s\n", ft_strchr("Hello World !", 'l'), strchr("Hello World !", 'l'));
	printf("----------------------------------------------------------------\n");
	printf("ft_strrchr : %s || strrchr : %s\n", ft_strrchr("Hello World !", 'l'), strrchr("Hello World !", 'l'));
	printf("----------------------------------------------------------------\n");
	printf("ft_strncmp : %d || strncmp : %d\n", ft_strncmp("Hello", "World !", 1), strncmp("Hello", "World !", 1));
	printf("----------------------------------------------------------------\n");
	const char	*s1 = "Hello World !";
	const char      *s2 = "Hello World !";
	const void	*p3;

	p2 = s1;
	p3 = s2;
	s1 = ft_memchr(p3, 'e', 2);
	s2 = memchr(p2, 'e', 2);
	printf("ft_memchr : %s || memchr : %s\n", s1, s2);
	printf("----------------------------------------------------------------\n");
	s1 = "hello";
	s2 = "Hello";
	printf("ft_memcmp : %d || memcmp : %d\n", ft_memcmp(s1, s2, 2), memcmp(s1, s2, 2));
	printf("----------------------------------------------------------------\n");
	//printf("ft_strnstr : %s || strnstr : %s\n", ft_strnstr("Hello World !", "Wo", 8), strnstr("Hello World !", "Wo", 8));
	printf("ft_atoi : %d || atoi : %d\n", ft_atoi(" \n +42"), atoi(" \n +42"));
	return (0);
}
