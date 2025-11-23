/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzehra <zzehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:34:48 by zzehra            #+#    #+#             */
/*   Updated: 2025/11/23 15:26:17 by zzehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H


# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>


#include <stdio.h>


typedef struct s_vars {
    void *mlx;
    void *win;
    void *img;
} t_vars ;

typedef struct s_map_3d {
    int x;
    int y;
    int z;
    int color;

    int iso_x;
    int iso_y;
} t_map_3d ;


#ifndef SIZE_X
#define SIZE_X 500
#endif 

#ifndef SIZE_Y
#define SIZE_Y 500
#endif

void    window_settings(t_vars **var, int x_len, int y_len);
int find_x_or_y(char *argv, char len);
void    read_map(char *argv, t_map_3d **arr_final);
void    find_isometric(t_map_3d **map, int x_len, int y_len);

#endif