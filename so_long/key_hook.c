/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:24:21 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/07 10:26:33 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    key_w(t_data *data)
{
    data->image_address = mlx_xpm_file_to_image(data->mlx, "src/black.xpm", &data->image_width, &data->image_height);
    mlx_put_image_to_window(data->mlx, data->window, data->image_address, data->char_x, data->char_y);
    data->char_y -= 32;
    data->image_address = mlx_xpm_file_to_image(data->mlx, "src/char.xpm", &data->image_width, &data->image_height);
    mlx_put_image_to_window(data->mlx, data->window, data->image_address, data->char_x, data->char_y);
    data->moves += 1;
    ft_printf("Moves : %d\n", data->moves);
}

void    key_a(t_data *data)
{
    data->image_address = mlx_xpm_file_to_image(data->mlx, "src/black.xpm", &data->image_width, &data->image_height);
    mlx_put_image_to_window(data->mlx, data->window, data->image_address, data->char_x, data->char_y);
    data->char_x -= 32;
    data->image_address = mlx_xpm_file_to_image(data->mlx, "src/char.xpm", &data->image_width, &data->image_height);
    mlx_put_image_to_window(data->mlx, data->window, data->image_address, data->char_x, data->char_y);
    data->moves += 1;
    ft_printf("Moves : %d\n", data->moves);
}

void    key_s(t_data *data)
{
    data->image_address = mlx_xpm_file_to_image(data->mlx, "src/black.xpm", &data->image_width, &data->image_height);
    mlx_put_image_to_window(data->mlx, data->window, data->image_address, data->char_x, data->char_y);
    data->char_y += 32;
    data->image_address = mlx_xpm_file_to_image(data->mlx, "src/char.xpm", &data->image_width, &data->image_height);
    mlx_put_image_to_window(data->mlx, data->window, data->image_address, data->char_x, data->char_y);
    data->moves += 1;
    ft_printf("Moves : %d\n", data->moves);
}

void    key_d(t_data *data)
{
    data->image_address = mlx_xpm_file_to_image(data->mlx, "src/black.xpm", &data->image_width, &data->image_height);
    mlx_put_image_to_window(data->mlx, data->window, data->image_address, data->char_x, data->char_y);
    data->char_x += 32;
    data->image_address = mlx_xpm_file_to_image(data->mlx, "src/char.xpm", &data->image_width, &data->image_height);
    mlx_put_image_to_window(data->mlx, data->window, data->image_address, data->char_x, data->char_y);
    data->moves += 1;
    ft_printf("Moves : %d\n", data->moves);
}

int	key_hook(int keycode, t_data *data)
{
    if (keycode == 119 && data->tab[data->char_y / 32 - 1][data->char_x / 32] != '1')
        key_w(data);
    else if (keycode == 97 && data->tab[data->char_y / 32][data->char_x / 32 - 1] != '1')
        key_a(data);
    else if (keycode == 115 && data->tab[data->char_y / 32 + 1][data->char_x / 32] != '1')
        key_s(data);
    else if (keycode == 100 && data->tab[data->char_y / 32][data->char_x / 32 + 1] != '1')
        key_d(data);
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