/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:48:23 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/13 22:53:47 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    free_tab(t_data *data)
{
    int     y;

    y = 0;
    while (data->tab[y])
    {
        free(data->tab[y]);
        y++;
    }
    free(data->tab);
}

int close_window(t_data *data)
{
    if (data->mlx && data->window)
    {
        mlx_destroy_window(data->mlx, data->window);
        mlx_destroy_display(data->mlx);
        free(data->mlx);
    }
    free(data->path);
    free(data->map);
    free_tab(data);
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

void    error(t_data *data)
{
    ft_printf("Error\n");
    close_window(data);
}

void    free_map(char **map)
{
    int     y;
    
    y = 0;
    while (map[y])
    {
        free(map[y]);
        y++;
    }
    free(map);
}