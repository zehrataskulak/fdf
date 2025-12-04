/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzehra <zzehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:38:53 by zzehra            #+#    #+#             */
/*   Updated: 2025/12/04 16:32:08 by zzehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void find_max_min(t_map **map, t_max_min *mm, int x_times_y)
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

void move_shape_to_origin(t_map **map, t_max_min *mm, int x_times_y)
{
    int indx;
    int x_shift_amount;
    int y_shift_amount;
    
    x_shift_amount = mm->x_min + (mm->x_max - mm->x_min) / 2;
    y_shift_amount = mm->y_min + (mm->y_max - mm->y_min) / 2;
    indx = 0;
    while(indx < x_times_y)
    {
        (*map)[indx].iso_x += x_shift_amount;
        (*map)[indx].iso_y += y_shift_amount;
        indx++;
    }
    
}


double calculate_zoom(t_max_min *mm)
{
    double zoom;
    double x_range;
    double y_range;

    x_range = (double)(mm->x_max - mm->x_min);
    y_range = (double)(mm->y_max - mm->y_min);
    zoom = 1;
    if((x_range < SIZE_X) && (y_range < SIZE_Y))
    {
        while ((x_range < SIZE_X) && (y_range < SIZE_Y))
        {
            zoom *= 1.1;
            x_range *= 1.1;
            y_range *= 1.1;
        }
        zoom /= 1.1;
        x_range /= 1.1;
        y_range /= 1.1;
    }
    else
    {
        while ((x_range >= SIZE_X) || (y_range >= SIZE_Y))
        {
            zoom /= 1.1;
            x_range /= 1.1;
            y_range /= 1.1;
        }
    }
    return (zoom);
}

double scale_map(t_map **map, int x_times_y)
{
    double zoom;
    int indx;
    t_max_min *mm;
    
    mm = malloc(sizeof(t_max_min));
    if (!mm)
        return (-1);
    move_shape_to_origin(map, mm, x_times_y);
    find_max_min(map, mm, x_times_y);
    zoom = calculate_zoom(mm);
    indx = 0;
    printf("\nzoom: %f\n", zoom);
    while(indx < x_times_y)
    {
        (*map)[indx].iso_x *= zoom;
        (*map)[indx].iso_y *= zoom;
        indx++;
    }
    free(mm);
    return (zoom);
}