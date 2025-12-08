/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzehra <zzehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:34:48 by zzehra            #+#    #+#             */
/*   Updated: 2025/12/08 20:47:55 by zzehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H


# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>


typedef struct s_vars {
    void *mlx;
    void *win;
    void *img;
    
    char *addr;
    int bpp;
    int line_len;
    int endian;
} t_vars ;

typedef struct s_map {
    int x;
    int y;
    int z;
    int color;

    int iso_x;
    int iso_y;
} t_map ;

typedef struct s_draw_lines_vars {
    int x_diff;
    int y_diff;
    int x_start;
    int y_start;
    int x_end;
    int y_end;
    int x_direction;
    int y_direction;
    int check_x_and_y;
    int chck_x_y_cntrl;
} t_draw_lines_vars ;

typedef struct s_max_min {
    int x_max;
    int x_min;
    int y_max;
    int y_min;

    double x_range;
    double y_range;
} t_max_min ;

#ifndef SIZE_X
#define SIZE_X 800
#endif

#ifndef SIZE_Y
#define SIZE_Y 500
#endif

#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

#ifndef INT_MIN
#define INT_MIN -2147483648
#endif


void    window_settings(t_vars **var, t_map *map, int x_len, int y_len);
int find_x_or_y(char *argv, char len);
void    read_map(char *argv, t_map **map, int x_len, int y_len);
void    find_isometric(t_map *map, int x_len, int y_len);
double scale_map(t_map *map, int x_times_y);
void put_dots(t_vars *var, t_map *map, int x_len, int y_len);
void draw_lines(t_vars *var, t_map *map, int x_len, int y_len);

#endif