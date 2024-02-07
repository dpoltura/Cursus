/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:57:33 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/07 11:08:56 by dpoltura         ###   ########.fr       */
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
    int     i;
    int     fd;
    char    *line;
    char    *map;
    char    *path;
    int     items;
}   t_data;

void    key_w(t_data *data);
void    key_a(t_data *data);
void    key_s(t_data *data);
void    key_d(t_data *data);
int	key_hook(int keycode, t_data *data);
int close_window(t_data *data);
void    put_obey(t_data *data);
void    put_bomb(t_data *data);
void    put_char(t_data *data);
void    put_exit(t_data *data);
void    new_line(t_data *data);

#endif