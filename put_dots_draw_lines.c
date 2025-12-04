/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_dots_draw_lines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzehra <zzehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:39:53 by zzehra            #+#    #+#             */
/*   Updated: 2025/12/03 21:09:58 by zzehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void put_dots(t_vars *var, t_map *map, int x_len, int y_len)
{
    int indx;

    indx = 0;
    while (indx < x_len * y_len)
    {
        //printf("%d, %d, %d\n", map[indx].iso_x, map[indx].iso_y, map[indx].color);
        mlx_pixel_put(var->mlx, var->win, map[indx].iso_x, map[indx].iso_y, map[indx].color);
        indx++;
    }
}


////////////////////////////////////////////////////////////////////////////////////
void draw_lines_0(t_draw_lines_vars *drw_var, t_map point_1, 
    t_map point_2)
{
    drw_var->x_start = point_1.iso_x;
    drw_var->y_start = point_1.iso_y;
    drw_var->x_end = point_2.iso_x;
    drw_var->y_end = point_2.iso_y;
    drw_var->x_diff = (int)fabs((double)(point_2.iso_x - drw_var->x_start));
    drw_var->y_diff = (int)fabs((double)(point_2.iso_y - drw_var->y_start));
    drw_var->x_direction = drw_var->x_start < drw_var->x_end ? 1 : -1;
    drw_var->y_direction = drw_var->y_start < drw_var->y_end ? 1 : -1;
    drw_var->check_x_and_y = drw_var->x_diff - drw_var->y_diff;
}

void draw_lines_1(t_vars *var, t_map point_1, t_map point_2)
{
    t_draw_lines_vars drw_var;

    draw_lines_0(&drw_var, point_1, point_2);
    
    while(1)
    {
        mlx_pixel_put(var->mlx, var->win, drw_var.x_start,
         drw_var.y_start, point_1.color);
        if((drw_var.x_start == drw_var.x_end) && (drw_var.y_start == drw_var.y_end))
            break ;
        drw_var.chck_x_y_cntrl = drw_var.check_x_and_y * 2;
        if(drw_var.chck_x_y_cntrl > -drw_var.y_diff)
        {
            drw_var.check_x_and_y -= drw_var.y_diff;
            drw_var.x_start += drw_var.x_direction;
        }
        if(drw_var.chck_x_y_cntrl < drw_var.x_diff)
        {
            drw_var.check_x_and_y += drw_var.x_diff;
            drw_var.y_start += drw_var.y_direction;
        }
    }
}

void draw_lines(t_vars *var, t_map *map, int x_len, int y_len)
{
    int indx;

    indx = 0;
    while(indx < x_len * y_len)
    {
        if ((indx + 1 < x_len * y_len) && ((indx + 1) % x_len != 0))
            draw_lines_1(var, map[indx], map[indx + 1]);
        if (indx + x_len < x_len * y_len)
            draw_lines_1(var, map[indx], map[indx + x_len]);
        indx++;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////