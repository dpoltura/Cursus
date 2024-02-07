/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:51:41 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/07 11:07:56 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->window);
    exit(0);
}

void    fd_map_error(t_data *data)
{
    data->fd = open(data->map, O_RDONLY);
    if (!data->fd || data->fd == -1)
    {
        perror(data->map);
        free(data->map);
        free(data->path);
        exit (0);
    }
}

void    window_width(t_data *data)
{
    int width;
    int i;
    
    fd_map_error(data);
    data->line = get_next_line(data->fd);
    data->tab = malloc(sizeof(char *) * 100);
    i = 0;
    while (data->line[i] != '\n')
        i++;
    width = i * 32;
    data->window_width = width;
    i = 0;
    while (data->line)
    {
        data->tab[i] = data->line;
        data->line = get_next_line(data->fd);
        i++;
    }
    free(data->line);
    close(data->fd);
}

void    window_height(t_data *data)
{
    int height;
    
    fd_map_error(data);
    data->line = get_next_line(data->fd);
    height = 0;
    while (data->line)
    {
        height += 32;
        free(data->line);
        data->line = get_next_line(data->fd);
    }
    data->window_height = height;
    free(data->line);
    close(data->fd);
}

void    draw_map(t_data *data)
{
    fd_map_error(data);
    data->line = get_next_line(data->fd);
    while (data->line)
    {
        while (data->line[data->i] == '1')
            put_obey(data);
        if (data->line[data->i] == 'C')
            put_bomb(data);
        else if (data->line[data->i] == 'P')
            put_char(data);
        else if (data->line[data->i] == 'E')
            put_exit(data);
        else if (data->line[data->i] == '\n')
            new_line(data);
        else if (data->line[data->i] == 'E' || data->line[data->i] == '0' || data->line[data->i] == 'P')
        {
            data->x += 32;
            data->i += 1;
        }
        else
            break ;
    }
    free(data->line);
    close(data->fd);
}

void    init_data(t_data *data)
{
    data->mlx = NULL;
    data->window = NULL;
    data->window_width = 0;
    data->window_height = 0;
    data->image = NULL;
    data->image_address = NULL;
    data->image_width = 0;
    data->image_height = 0;
    data->x = 0;
    data->y = 0;
    data->char_x = 0;
    data->char_y = 0;
    data->tab = NULL;
    data->moves = 0;
    data->i = 0;
}

int main(int argc, char **argv)
{
    t_data  data;

    if (argc != 2)
        return (0);
    data.path = ft_strjoin(argv[1], ".ber");
    data.map = ft_strjoin("map/", data.path);
    init_data(&data);
    window_width(&data);
    window_height(&data);
    data.mlx = mlx_init();
    data.window = mlx_new_window(data.mlx, data.window_width, data.window_height, "so_long");
    draw_map(&data);
    mlx_key_hook(data.window, key_hook, &data);
    mlx_hook(data.window, 17, 1L << 17, close_window, &data);
    mlx_loop(data.mlx);
    free(data.path);
    free(data.map);
    return (0);
}