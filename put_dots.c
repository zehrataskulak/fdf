/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_dots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzehra <zzehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:39:53 by zzehra            #+#    #+#             */
/*   Updated: 2025/11/12 11:02:56 by zzehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void put_dots(t_vars **var, t_map_3d *map, int x_len, int y_len)
{
    int x;
    int y;
    int indx;

    indx = 0;
    y = 0;
    while (y < y_len)
    {
        x = 0;
        while (x < x_len)
        {
            //mlx_pixel_put((*var)->mlx, (*var)->win, map[indx].x, map[indx].y, 0xFFFFFF);
            x++;
            indx++;
        }
        y++;
    }

    //mlx_pixel_put((*var)->mlx, (*var)->win, )
}