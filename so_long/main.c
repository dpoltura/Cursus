/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:51:41 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/23 13:20:15 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->window);
    exit(0);
}

void    window_size(char *map, t_data *data)
{
    int fd;
    char    buffer[1];
    int window_width;
    int window_height;

    fd = open(map, O_RDONLY);
    if (fd == -1)
    {
        perror("\033[1;31m[MAP ERROR]");
        exit(EXIT_FAILURE);
    }
    window_width = 0;
    window_height = 0;
    read(fd, buffer, sizeof(buffer));
    while (fd)
    {
        while (buffer[0] != '\n')
        {
            read(fd, buffer, sizeof(buffer));
            if (!window_height)
                window_width += 32;
        }
        window_height += 32;
        break ;
    }
    data->window_height = window_height;
    data->window_width = window_width;
    close(fd);
}

void    draw_map(char *map, t_data *data)
{
    int fd;
    char    buffer[1];

    fd = open(map, O_RDONLY);
    data->x = 0;
    data->y = 0;
    while (fd)
    {
        read(fd, buffer, sizeof(buffer));
        if (buffer[0] == '1')
            data->image_address = mlx_xpm_file_to_image(data->mlx, "New-Piskel.xpm", &data->image_width, &data->image_height);
        else
            break ;
        mlx_put_image_to_window(data->mlx, data->window, data->image_address, data->x, data->y);
        data->x += 32;
    }
    close(fd);
}

int main(int argc, char **argv)
{
    t_data  data;
    char    *map;

    if (argc != 2)
        return (0);
    map = ft_strjoin(argv[1], ".ber");
    window_size(map, &data);
    data.mlx = mlx_init();
    data.window = mlx_new_window(data.mlx, data.window_width, data.window_height, "so_long");
    draw_map(map, &data);
    mlx_hook(data.window, 17, 1L << 17, close_window, &data);
    mlx_loop(data.mlx);
    free(map);
    return (0);
}