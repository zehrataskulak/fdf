/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzehra <zzehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:44:27 by zzehra            #+#    #+#             */
/*   Updated: 2025/11/24 15:05:24 by zzehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	find_x_0(char *str)
{
	int	x_len;
    char **splitted_x;
    int i;

    i = 0;
    x_len = 0;
    splitted_x = ft_split(str, ' ');
    while(splitted_x[i])
    {
        if(splitted_x[i][0] != '\n')
            x_len++;
        i++;
    }   
    i = 0;
    while(splitted_x[i])
        free(splitted_x[i++]);
    free(splitted_x);
	return (x_len);
}

int find_x_or_y(char *argv, char len)
{
    int fd;
    char *str;
    int x_len;
    static int y_len;
    
    if(len == 'x')
    {
        y_len = 0;
        fd = open(argv, O_RDONLY);
        str = get_next_line(fd);
        x_len = find_x_0(str);
        while(str)
        {
            y_len++;
            free(str);
            str = get_next_line(fd);
        }
        close(fd);
        return (x_len);
    }
    return(y_len);
}