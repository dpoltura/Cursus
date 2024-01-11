/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:51:41 by dpoltura          #+#    #+#             */
/*   Updated: 2024/01/11 13:46:08 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_win(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    exit (0);
}

int main(void)
{
    t_data  data;
    
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 333, 333, "test");
    mlx_hook(data.win, 17, 1L << 17, close_win, &data);
    mlx_loop(data.mlx);
    return (0);
}