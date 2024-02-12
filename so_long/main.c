/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:51:41 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/12 19:46:28 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    error(t_data *data)
{
    ft_printf("Error\n");
    close_window(data);
}

void    check_rectangle(t_data *data)
{
    int     y;
    int     x;
    int     size;

    y = 0;
    x = 0;
    while (data->tab[y][x])
        x++;
    size = x;
    y++;
    while (data->tab[y])
    {
        x = 0;
        while (data->tab[y][x])
            x++;
        if (y == (data->window_height / 32) - 1)
            x++;
        if (size != x)
            error(data);
        size = x;
        y++;
    }
    if (y < 2)
        error(data);
}

void    check_wall(t_data *data)
{
    int     y;
    int     x;

    y = 0;
    x = 0;
    while (data->tab[y])
    {
        while (data->tab[y][x])
        {
            if ((y == 0 || y == (data->window_height / 32) - 1) && (data->tab[y][x] != '1' && data->tab[y][x] != '\n'))
                error(data);
            if ((x == 0 || x == (data->window_width / 32) - 1) && (data->tab[y][x] != '1' && data->tab[y][x] != '\n'))
                error(data);
            x++;
        }
        x = 0;
        y++;
    }
}

void    check_epc(t_data *data)
{
    int     y;
    int     x;
    
    y = 0;
    x = 0;
    while (data->tab[y])
    {
        while (data->tab[y][x])
        {
            if (data->tab[y][x] == 'E')
                data->epc[0]++;
            else if (data->tab[y][x] == 'P')
                data->epc[1]++;
            else if (data->tab[y][x] == 'C')
                data->epc[2]++;
            x++;
        }
        x = 0;
        y++;
    }
    if (data->epc[0] != 1 || data->epc[1] != 1 || data->epc[2] < 1)
        error(data);
}

void    check_characters(t_data *data)
{
    int     y;
    int     x;

    y = 0;
    x = 0;
    while (data->tab[y])
    {
        while (data->tab[y][x])
        {
            if (data->tab[y][x] != 'E' && data->tab[y][x] != 'P'
                && data->tab[y][x] != 'C' && data->tab[y][x] != '0'
                && data->tab[y][x] != '1' && data->tab[y][x] != '\n')
                error(data);
            x++;
        }
        x = 0;
        y++;
    }
}

void    char_pos(t_data *data)
{
    int     y;
    int     x;
    
    y = 0;
    while (data->tab[y])
    {
        x = 0;
        while (data->tab[y][x] != 'P' && data->tab[y][x] != '\n')
            x++;
        if (data->tab[y][x] == 'P')
            break ;
        y++;
    }
    data->y = y;
    data->x = x;
}

void    floodfill(int x, int y, char **map, t_data *data)
{
    if (x < 0 || x >= data->window_width / 32
        || y < 0 || y >= data->window_height / 32
        || map[y][x] == '1' || map[y][x] == 'V')
        return ;
    map[y][x] = 'V';
    floodfill(x + 1, y, map, data);
    floodfill(x - 1, y, map, data);
    floodfill(x, y + 1, map, data);
    floodfill(x, y - 1, map, data);
}

void    check_after_floodfill(char **map, t_data *data)
{
    int     y;
    int     x;

    y = 0;
    x = 0;
    while (map[y])
    {
        while (map[y][x])
        {
            if (map[y][x] == 'E' || map[y][x] == 'C')
                error(data);
            x++;
        }
        x = 0;
        y++;
    }
}

char    **clone_map(t_data *data)
{
    char    **map;
    int     y;
    
    map = ft_calloc(sizeof(char *), 100);
    y = 0;
    while (data->tab[y])
    {
        map[y] = ft_strdup(data->tab[y]);
        y++;
    }
    return (map);
}

void    check_all(t_data *data)
{
    char    **map;

    map = clone_map(data);
    check_rectangle(data);
    check_wall(data);
    check_epc(data);
    check_characters(data);
    char_pos(data);
    floodfill(data->x, data->y, map, data);
    check_after_floodfill(map, data);
    free(map);
    data->x = 0;
    data->y = 0;
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
    check_all(&data);
    data.mlx = mlx_init();
    data.window = mlx_new_window(data.mlx, data.window_width, data.window_height, "so_long");
    draw_map(&data);
    items(&data);
    mlx_key_hook(data.window, key_hook, &data);
    mlx_hook(data.window, 17, 1L << 17, close_window, &data);
    mlx_loop(data.mlx);
    return (0);
}