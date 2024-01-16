/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:57:33 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/11 16:35:21 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 16

# include "minilibx-linux/mlx.h"
# include <stdlib.h>

typedef struct  s_data
{
    void    *mlx;
    void    *window;
}   t_data;

typedef struct  s_size
{
    int width;
    int height;
}   t_size;

typedef struct  s_image {
    void    *image;
    char    *address;
    int bits_per_pixel;
    int size_line;
    int endian;
} t_image;

#endif