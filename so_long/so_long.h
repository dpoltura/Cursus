/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:57:33 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/07 09:43:26 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/minilibx-linux/mlx.h"
# include "lib/libft/libft.h"
# include "lib/get_next_line/get_next_line.h"
# include "lib/ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct  s_data
{
    void    *mlx;
    void    *window;
    int     window_width;
    int     window_height;
    void    *image;
    char    *image_address;
    int     image_width;
    int     image_height;
    int     x;
    int     y;
    int     char_x;
    int     char_y;
    char    **tab;
    int     moves;
}   t_data;

#endif