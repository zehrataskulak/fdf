/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_isometric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzehra <zzehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:03:23 by zzehra            #+#    #+#             */
/*   Updated: 2025/11/26 12:45:12 by zzehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*double find_scale(int x_len, int y_len)
{
    int max_len;
    double scale;

    if(x_len >= y_len)
    {
        max_len = x_len;
        scale = (SIZE_X / 2.0) / (double)max_len;
    }   
    else
    {
        max_len = y_len;
        scale = (SIZE_Y / 2.0) / (double)max_len;
    }
    return (scale);
}*/


void    find_isometric_0(t_map **map, int x_len, int y_len)
{
    int x;
    int y;
    int indx;
    //double scale;
    
    y = 0;
    indx = 0;
    //scale = find_scale(x_len, y_len);
    while (y < y_len)
    {
        x = 0;
        while(x < x_len)
        {
            (*map)[indx].iso_x = ((*map)[indx].x - (*map)[indx].y) * cos(0.523599);
            (*map)[indx].iso_y = ((*map)[indx].x + (*map)[indx].y) * sin(0.523599) - (*map)[indx].z * ( 0.2);
            indx++;
            x++;
        }
        y++;
    }
}

void find_shift_amount(t_map *map, int *x_shift, int *y_shift, int x_times_y)
{
    t_max_min mm;
    int indx;
    
    indx = 0;
    mm.x_min = INT_MAX;
    mm.x_max = INT_MIN;
    mm.y_min = INT_MAX;
    mm.y_max = INT_MIN;
    while(indx < x_times_y)
    {
        if (map[indx].iso_x < mm.x_min)
            mm.x_min = map[indx].iso_x;
        if (map[indx].iso_x > mm.x_max)
            mm.x_max = map[indx].iso_x;
        if (map[indx].iso_y < mm.y_min)
            mm.y_min = map[indx].iso_y;
        if (map[indx].iso_y > mm.y_max)
            mm.y_max = map[indx].iso_y;
        indx++;
    }
    *x_shift = (SIZE_X - (mm.x_max - mm.x_min)) / 2 - mm.x_min;
    *y_shift = (SIZE_Y - (mm.y_max - mm.y_min)) / 2 - mm.y_min;
}

void find_isometric(t_map **map, int x_len, int y_len)
{
    int indx;
    int x_times_y;
    int x_shift;
    int y_shift;

    indx = 0;
    x_times_y = x_len * y_len;
    //find_isometric_0(map, x_len, y_len);
    /* scale the map to fit in the window */
    scale_map(map, x_times_y);
    find_shift_amount(*map, &x_shift, &y_shift, x_times_y);
    while (indx < x_times_y)
    {
        (*map)[indx].iso_x += x_shift;
        (*map)[indx].iso_y += y_shift;
        indx++;
    }
    //scale_map(map, x_times_y);
}