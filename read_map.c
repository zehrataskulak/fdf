/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzehra <zzehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:13:16 by zzehra            #+#    #+#             */
/*   Updated: 2025/11/23 14:01:52 by zzehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


/*
int find_y(char *argv)
{
    int fd;
    char *str;
    int y_len;

    y_len = 0;
    fd = open(argv, O_RDONLY);
    str = get_next_line(fd);
    while(str)
    {
        y_len++;
        free(str);
        str = get_next_line(fd);
    }
    close(fd);
    return(y_len);
}

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

int    find_x(char *argv)
{
    int fd;
    char *str;
    int x_len;
    int y_len;
    
    
    fd = open(argv, O_RDONLY);
    str = get_next_line(fd);
    x_len = find_x_0(str);
    //get_next_line yi 1 kere çağırdığımızda fd yi kapatsak bile static te değer kallıyor. o yüzden dosyayı bitiriyorum 
    while(str)
    {
        free(str);
        str = get_next_line(fd);
    }
    close(fd);
    return(x_len);
}

void    copy_as_int(char *argv, t_map_3d *arr_final, int x_len, int y_len)
{
    int fd;
    char *str;
    char **arr_split;
    int i;
    int j;
    int indx;
    
    indx = 0;
    i = 0;
    fd = open(argv, O_RDONLY);
    str = get_next_line(fd);
    while(str)
    {
        j = 0;
        arr_split = ft_split(str, ' ');
        while(arr_split[j] && (arr_split[j][0] != '\n'))
        {
            
            //(*arr_final).map[i][j] = ft_atoi(arr_split[j]);
            arr_final[indx].z = ft_atoi(arr_split[j]);
            arr_final[indx].y = j;
            arr_final[indx].x = i;
            j++;
            indx++;
        }
        j = 0;
        while (arr_split[j])
            free(arr_split[j++]);
        free(arr_split);
        free(str);
        str = get_next_line(fd);
        i++;
        if(indx == x_len + y_len - 1)
            break;
    }
    close(fd);
}

void    read_map(char *argv, t_map_3d **arr_final)
{
    int y_len;
    int x_len;
    int i;
    

    i = 0;
    x_len = find_x(argv);
    y_len = find_y(argv);
    printf("x_len: %d, y_len:%d\n", x_len, y_len);


    *arr_final = malloc(sizeof(t_map_3d) * (x_len * y_len));
    if (!*arr_final)
        return ;
    
    /*(*arr_final).y = malloc(sizeof(int *) * y_len);
    if(!(*arr_final).map)
        return ;
    while(i < y_len)
    {
        (*arr_final).map[i] = malloc(sizeof(int) * x_len);
        if(!(*arr_final).map[i])
            return ;
        i++;
    //}
    copy_as_int(argv, *arr_final, x_len, y_len);
}
*/

/*int find_x_help(char *str)
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

void copy_as_int_1(char *str, t_map_3d **arr_final, int y_len, int x_len)
{
    char **arr_split;
    int i;
    int indx;

    i = 0;
    indx = 0;
    arr_split = ft_split(str, ' ');
    *arr_final[y_len - 1] = malloc(sizeof(t_map_3d) * (x_len));
    if (!*arr_final)
        return ;
    while(arr_split[i] && (arr_split[i][0] != '\n'))
    {
        //(*arr_final).map[i][j] = ft_atoi(arr_split[j]);
        arr_final[indx]->z = ft_atoi(arr_split[i]);
        arr_final[indx]->y = i;
        arr_final[indx]->x = y_len - 1;
        i++;
        indx++;
    }
}

int find_len_read_map(char *argv, t_map_3d **arr_final, char len_x_y)
{
    int fd;
    char *str;
    int y_len;
    int x_len;

    y_len = 0;
    fd = open(argv, O_RDONLY);
    str = get_next_line(fd);
    x_len = find_x_help(str);
    while(str)
    {
        y_len++;
        copy_as_int_1(str, arr_final, y_len, x_len);
        free(str);
        str = get_next_line(fd);
    }
    close(fd);
    if(len_x_y == 'x')
        return (x_len);
    return (y_len);
}*/

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
        //get_next_line yi 1 kere çağırdığımızda fd yi kapatsak bile static te değer kallıyor. o yüzden dosyayı bitiriyorum 
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

void    copy_as_int(char *argv, t_map_3d *arr_final, int x_len, int y_len)
{
    int fd;
    char *str;
    char **arr_split;
    int i;
    int j;
    int indx;
    
    indx = 0;
    i = 0;
    fd = open(argv, O_RDONLY);
    str = get_next_line(fd);
    while(str)
    {
        j = 0;
        arr_split = ft_split(str, ' ');
        while(arr_split[j] && (arr_split[j][0] != '\n'))
        {
            
            //(*arr_final).map[i][j] = ft_atoi(arr_split[j]);
            arr_final[indx].z = ft_atoi(arr_split[j]);
            arr_final[indx].y = j;
            arr_final[indx].x = i;
            j++;
            indx++;
        }
        j = 0;
        while (arr_split[j])
            free(arr_split[j++]);
        free(arr_split);
        free(str);
        str = get_next_line(fd);
        i++;
        if(indx == x_len + y_len - 1)
            break;
    }
    close(fd);
}

void    read_map(char *argv, t_map_3d **arr_final)
{
    int y_len;
    int x_len;
    int i;
    

    i = 0;
    x_len = find_x_or_y(argv, 'x');
    y_len = find_x_or_y(argv, 'y');
    printf("x_len: %d, y_len:%d\n", x_len, y_len);


    *arr_final = malloc(sizeof(t_map_3d) * (x_len * y_len));
    if (!*arr_final)
        return ;
    
    /*(*arr_final).y = malloc(sizeof(int *) * y_len);
    if(!(*arr_final).map)
        return ;
    while(i < y_len)
    {
        (*arr_final).map[i] = malloc(sizeof(int) * x_len);
        if(!(*arr_final).map[i])
            return ;
        i++;
    }*/
    copy_as_int(argv, *arr_final, x_len, y_len);
}