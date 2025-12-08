/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzehra <zzehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:13:16 by zzehra            #+#    #+#             */
/*   Updated: 2025/12/08 20:18:24 by zzehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi_hex(const char *str)
{
    int num;
    int i;

    num = 0;
    i = 0;
    if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
        i = 2;
    while (str[i])
    {
        num *= 16;
        if (str[i] >= '0' && str[i] <= '9')
            num += str[i] - '0';
        else if (str[i] >= 'A' && str[i] <= 'F')
            num += str[i] - 'A' + 10;
        else if (str[i] >= 'a' && str[i] <= 'f')
            num += str[i] - 'a' + 10;
        i++;
    }
    return num;
}

void    split_numbers(char *str, t_map *map, int i, int *indx)
{
    int j;
    char **arr_split;
    char **split_color;

    j = 0;
    arr_split = ft_split(str, ' ');
    while(arr_split[j] && (arr_split[j][0] != '\n'))
    {
        map[*indx].color = ft_atoi_hex("0xFFFFFF");
        if(ft_strchr(arr_split[j], ','))
        {
            split_color = ft_split(arr_split[j], ',');
            map[*indx].color = ft_atoi_hex(split_color[1]);
            free(split_color[0]);
            free(split_color[1]);
            free(split_color);
        }
        map[*indx].z = ft_atoi(arr_split[j]);
        map[*indx].y = i;
        map[(*indx)++].x = j++;
    }
    j = 0;
    while (arr_split[j])
        free(arr_split[j++]);
    free(arr_split);
}

void    copy_as_int(char *argv, t_map *map, int x_len, int y_len)
{
    int fd;
    char *str;
    int i;
    int indx;
    
    indx = 0;
    i = 0;
    fd = open(argv, O_RDONLY);
    str = get_next_line(fd);
    while(str)
    {
        split_numbers(str, map, i, &indx);
        free(str);
        str = get_next_line(fd);
        i++;
        if (indx >= x_len * y_len)
            break;
    }
    close(fd);
}

void    read_map(char *argv, t_map **map, int x_len, int y_len)
{
    *map = ft_calloc((x_len * y_len), sizeof(t_map));
    if (!*map)
        return ;
    copy_as_int(argv, *map, x_len, y_len);
}