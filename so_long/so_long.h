/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:57:33 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/25 15:05:22 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
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
}   t_data;

#endif