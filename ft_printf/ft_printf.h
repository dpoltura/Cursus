/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:59:26 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/23 15:42:24 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int ft_printf( const char *format, ... );
int	ft_putnbr_x(unsigned int n, char *base, int fd);
int ft_print_s(char *tmp, char *args, int j);
int ft_print_c(int args, int j);
int ft_print_p(long tmp, int j, long args);

#endif