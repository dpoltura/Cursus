/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:51:41 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/27 13:30:45 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->window);
    exit(0);
}

int    fd_map_error(char *map)
{
    int     fd;

    fd = open(map, O_RDONLY);
    if (!fd || fd == -1)
    {
        perror(map);
        free(map);
        exit (0);
    }
    return (fd);
}

void    window_width(char *map, t_data *data)
{
    int fd;
    char    *line;
    int width;
    int i;
    
    fd = fd_map_error(map);
    line = get_next_line(fd);
    data->tab = malloc(sizeof(char *) * 100);
    i = 0;
    while (line[i] != '\n')
        i++;
    width = i * 32;
    data->window_width = width;
    i = 0;
    while (line)
    {
        data->tab[i] = line;
        line = get_next_line(fd);
        i++;
    }
    close(fd);
}

void    window_height(char *map, t_data *data)
{
    int fd;
    char    *line;
    int height;
    
    fd = fd_map_error(map);
    line = get_next_line(fd);
    height = 0;
    while (line)
    {
        height += 32;
        line = get_next_line(fd);
    }
    data->window_height = height;
    close(fd);
}

void    draw_map(char *map, t_data *data)
{
    int fd;
    char    *line;
    int i;

    fd = fd_map_error(map);
    line = get_next_line(fd);
    i = 0;
    while (line)
    {
        while (line[i] == '1')
        {
            data->image_address = mlx_xpm_file_to_image(data->mlx, "obey.xpm", &data->image_width, &data->image_height);
            mlx_put_image_to_window(data->mlx, data->window, data->image_address, data->x, data->y);
            data->x += 32;
            i++;
        }
        if (line[i] == 'C')
        {
            data->image_address = mlx_xpm_file_to_image(data->mlx, "bomb.xpm", &data->image_width, &data->image_height);
            mlx_put_image_to_window(data->mlx, data->window, data->image_address, data->x, data->y);
            data->x += 32;
            i++;
        }
        else if (line[i] == 'P')
        {
            data->image_address = mlx_xpm_file_to_image(data->mlx, "char.xpm", &data->image_width, &data->image_height);
            mlx_put_image_to_window(data->mlx, data->window, data->image_address, data->x, data->y);
            data->char_x = data->x;
            data->char_y = data->y;
            data->x += 32;
            i++;
        }
        else if (line[i] == 'E')
        {
            data->image_address = mlx_xpm_file_to_image(data->mlx, "exit.xpm", &data->image_width, &data->image_height);
            mlx_put_image_to_window(data->mlx, data->window, data->image_address, data->x, data->y);
            data->x += 32;
            i++;
        }
        else if (line[i] == '\n')
        {
            data->y += 32;
            line = get_next_line(fd);
            i = 0;
            data->x = 0;
        }
        else if (line[i] == 'E' || line[i] == '0' || line[i] == 'P')
        {
            data->x += 32;
            i++;
        }
        else
            break ;
    }
    close(fd);
}

int	key_hook(int keycode, t_data *data)
{
    if (keycode == 119 && data->tab[data->char_y / 32 - 1][data->char_x / 32] != '1')
    {
        data->image_address = mlx_xpm_file_to_image(data->mlx, "black.xpm", &data->image_width, &data->image_height);
        mlx_put_image_to_window(data->mlx, data->window, data->image_address, data->char_x, data->char_y);
        data->char_y -= 32;
        data->image_address = mlx_xpm_file_to_image(data->mlx, "char.xpm", &data->image_width, &data->image_height);
        mlx_put_image_to_window(data->mlx, data->window, data->image_address, data->char_x, data->char_y);
        data->moves += 1;
        ft_printf("Moves : %d\n", data->moves);
    }
    else if (keycode == 97 && data->tab[data->char_y / 32][data->char_x / 32 - 1] != '1')
    {
        data->image_address = mlx_xpm_file_to_image(data->mlx, "black.xpm", &data->image_width, &data->image_height);
        mlx_put_image_to_window(data->mlx, data->window, data->image_address, data->char_x, data->char_y);
        data->char_x -= 32;
        data->image_address = mlx_xpm_file_to_image(data->mlx, "char.xpm", &data->image_width, &data->image_height);
        mlx_put_image_to_window(data->mlx, data->window, data->image_address, data->char_x, data->char_y);
        data->moves += 1;
        ft_printf("Moves : %d\n", data->moves);
    }
    else if (keycode == 115 && data->tab[data->char_y / 32 + 1][data->char_x / 32] != '1')
    {
        data->image_address = mlx_xpm_file_to_image(data->mlx, "black.xpm", &data->image_width, &data->image_height);
        mlx_put_image_to_window(data->mlx, data->window, data->image_address, data->char_x, data->char_y);
        data->char_y += 32;
        data->image_address = mlx_xpm_file_to_image(data->mlx, "char.xpm", &data->image_width, &data->image_height);
        mlx_put_image_to_window(data->mlx, data->window, data->image_address, data->char_x, data->char_y);
        data->moves += 1;
        ft_printf("Moves : %d\n", data->moves);
    }
    else if (keycode == 100 && data->tab[data->char_y / 32][data->char_x / 32 + 1] != '1')
    {
        data->image_address = mlx_xpm_file_to_image(data->mlx, "black.xpm", &data->image_width, &data->image_height);
        mlx_put_image_to_window(data->mlx, data->window, data->image_address, data->char_x, data->char_y);
        data->char_x += 32;
        data->image_address = mlx_xpm_file_to_image(data->mlx, "char.xpm", &data->image_width, &data->image_height);
        mlx_put_image_to_window(data->mlx, data->window, data->image_address, data->char_x, data->char_y);
        data->moves += 1;
        ft_printf("Moves : %d\n", data->moves);
    }
    else if (keycode == 65307 || keycode == 17)
    {
        close_window(data);
        exit (0);
    }
    if (data->tab[data->char_y / 32][data->char_x / 32] == 'E')
    {
        exit (0);
    }
	return (0);
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
}

int main(int argc, char **argv)
{
    t_data  data;
    char    *map;

    if (argc != 2)
        return (0);
    map = ft_strjoin(argv[1], ".ber");
    init_data(&data);
    window_width(map, &data);
    window_height(map, &data);
    data.mlx = mlx_init();
    data.window = mlx_new_window(data.mlx, data.window_width, data.window_height, "so_long");
    draw_map(map, &data);
    mlx_key_hook(data.window, key_hook, &data);
    mlx_hook(data.window, 17, 1L << 17, close_window, &data);
    mlx_loop(data.mlx);
    free(map);
    return (0);
}