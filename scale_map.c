/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzehra <zzehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:38:53 by zzehra            #+#    #+#             */
/*   Updated: 2025/11/26 12:47:17 by zzehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void scale_map_0(t_map **map, t_max_min *mm, int x_times_y)
{

    int indx;
    
    
    mm->x_max = INT_MIN;
    mm->x_min = INT_MAX;
    mm->y_max = INT_MIN;
    mm->y_min = INT_MAX;
    indx = 0;
    while(indx < x_times_y)
    {
        if ((*map)[indx].iso_x < mm->x_min)
            mm->x_min = (*map)[indx].iso_x;
        if ((*map)[indx].iso_x > mm->x_max)
            mm->x_max = (*map)[indx].iso_x;
        if ((*map)[indx].iso_y < mm->y_min)
            mm->y_min = (*map)[indx].iso_y;
        if ((*map)[indx].iso_y > mm->y_max)
            mm->y_max = (*map)[indx].iso_y;
        indx++;
    }
}

double calculate_zoom(t_max_min *mm)
{
    double x_range;
    double y_range;
    double x_zoom;
    double y_zoom;
    double zoom;
    
    
    x_range = (double)(mm->x_max - mm->x_min);
    y_range = (double)(mm->y_max - mm->y_min);
    
    /* calculate how much we need to scale to fit in the window with 10% padding */
    x_zoom = (SIZE_X * 0.9) / x_range;
    y_zoom = (SIZE_Y * 0.9) / y_range;
    
    /* use the smaller zoom factor to ensure everything fits */
    zoom = (x_zoom < y_zoom) ? x_zoom : y_zoom;
    
    return (zoom);
}

void scale_map(t_map **map, int x_times_y)
{
    double zoom;
    int indx;
    t_max_min *mm;
    
    mm = malloc(sizeof(t_max_min));
    if (!mm)
        return ;
    scale_map_0(map, mm, x_times_y);
    zoom = calculate_zoom(mm);
    
    indx = 0;
    while(indx < x_times_y)
    {
        (*map)[indx].iso_x = (int)((*map)[indx].iso_x * zoom);
        (*map)[indx].iso_y = (int)((*map)[indx].iso_y * zoom);
        indx++;
    }
}