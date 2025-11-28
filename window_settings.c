/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzehra <zzehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:56:15 by zzehra            #+#    #+#             */
/*   Updated: 2025/11/26 09:29:37 by zzehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int close_window_cross(t_vars **var)
{
    mlx_destroy_image((*var)->mlx, (*var)->img);
    mlx_destroy_window((*var)->mlx, (*var)->win);
    mlx_destroy_display((*var)->mlx);
    free((*var)->mlx);
    free(*var);
    exit(0);
    return (0);
}

int close_window_esc(int key, t_vars **vars)
{
    if(key == 65307)
        close_window_cross(vars);
    return (0);
}

void    window_settings(t_vars **var, t_map *map, int x_len, int y_len)
{   
    (*var)->mlx = mlx_init();
    (*var)->win = mlx_new_window((*var)->mlx, SIZE_X, SIZE_Y, "FDF");
    (*var)->img = mlx_new_image((*var)->mlx, SIZE_X, SIZE_Y);

    put_dots(*var, map, x_len, y_len);
    draw_lines(*var, map, x_len, y_len);
    
    mlx_hook((*var)->win, 17, 0, close_window_cross, var);
    mlx_key_hook((*var)->win, close_window_esc, var);
}