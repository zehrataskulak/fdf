/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzehra <zzehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:38:53 by zzehra            #+#    #+#             */
/*   Updated: 2025/12/05 16:27:38 by zzehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void find_max_min(t_map *map, t_max_min *mm, int x_times_y)
{
    int indx;
    
    mm->x_max = INT_MIN;
    mm->x_min = INT_MAX;
    mm->y_max = INT_MIN;
    mm->y_min = INT_MAX;
    indx = 0;
    while(indx < x_times_y)
    {
        if (map[indx].iso_x < mm->x_min)
            mm->x_min = map[indx].iso_x;
        if (map[indx].iso_x > mm->x_max)
            mm->x_max = map[indx].iso_x;
        if (map[indx].iso_y < mm->y_min)
            mm->y_min = map[indx].iso_y;
        if (map[indx].iso_y > mm->y_max)
            mm->y_max = map[indx].iso_y;
        indx++;
    }
    mm->x_range = (double)(mm->x_max - mm->x_min);
    mm->y_range = (double)(mm->y_max - mm->y_min);
}

double calculate_zoom(t_max_min *mm)
{
    double zoom;

    zoom = 1;
    if((mm->x_range < SIZE_X) && (mm->y_range < SIZE_Y))
    {
        while ((mm->x_range < SIZE_X) && (mm->y_range < SIZE_Y))
        {
            zoom *= 1.1;
            mm->x_range *= 1.1;
            mm->y_range *= 1.1;
        }
        zoom /= 1.1;
        mm->x_range /= 1.1;
        mm->y_range /= 1.1;
    }
    else
    {
        while ((mm->x_range >= SIZE_X) || (mm->y_range >= SIZE_Y))
        {
            zoom /= 1.1;
            mm->x_range /= 1.1;
            mm->y_range /= 1.1;
        }
    }
    return (zoom);
}

double scale_map(t_map *map, int x_times_y)
{
    double zoom;
    int indx;
    t_max_min *mm;
    
    mm = malloc(sizeof(t_max_min));
    if (!mm)
        return (-1);
    find_max_min(map, mm, x_times_y);
    zoom = calculate_zoom(mm);
    indx = 0;
    while(indx < x_times_y)
    {
        map[indx].iso_x *= zoom;
        map[indx].iso_y *= zoom;
        indx++;
    }
    free(mm);
    return (zoom);
}