/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:51:41 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/11 16:53:20 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->window);
    exit (0);
}

int main(void)
{
    t_data  data;
    t_size  window;
    t_image image;
    t_size  xpm;
    
    window.width = 456;
    window.height = 456;
    data.mlx = mlx_init();
    data.window = mlx_new_window(data.mlx, window.width, window.height, "so_long");
    
    image.image = mlx_xpm_file_to_image(data.mlx, "tileset_cpy.xpm", &xpm.width, &xpm.height);
    image.address = mlx_get_data_addr(image.image, &image.bits_per_pixel, &image.size_line, &image.endian);
    mlx_put_image_to_window(data.mlx, data.window, image.image, 0, 0);
    
    mlx_hook(data.window, 17, 1L << 17, close_window, &data);
    mlx_loop(data.mlx);
    return (0);
}