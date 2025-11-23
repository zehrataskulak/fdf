/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_isometric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzehra <zzehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:03:23 by zzehra            #+#    #+#             */
/*   Updated: 2025/11/12 11:17:32 by zzehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    find_isometric(t_map_3d **map, int x_len, int y_len)
{
    int x;
    int y;
    int indx;

    y = 0;
    indx = 0;
    while (y < y_len)
    {
        x = 0;
        while(x < x_len)
        {
            (*map)[indx].iso_x = ((*map)[indx].x - (*map)[indx].y) * cos(0.523599);
            (*map)[indx].iso_y = ((*map)[indx].x + (*map)[indx].y) * sin(0.523599) - (*map)[indx].z;
            indx++;
            x++;
        }
        y++;
    }
}
