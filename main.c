/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzehra <zzehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:34:27 by zzehra            #+#    #+#             */
/*   Updated: 2025/11/26 09:31:42 by zzehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
    t_vars  *var;
    t_map   *mapi;
    int y_len;
    int x_len;
    (void)argc;
    
    x_len = find_x_or_y(argv[1], 'x');
    y_len = find_x_or_y(argv[1], 'y');
    read_map(argv[1], &mapi);
    

    // only for printing the values
    int indx = 0;
    /*for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            printf("%d,%d,%d ", mapi[indx].x, mapi[indx].y, mapi[indx].z);
            indx++;
        }
        printf("\n");
    }
    

    printf("\n");
    printf("\n");*/
    find_isometric(&mapi, x_len, y_len);

    indx = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            printf("%d,%d ", mapi[indx].iso_x, mapi[indx].iso_y);
            indx++;
        }
        printf("\n");
    }
    
    
    var = malloc(sizeof(t_vars));
    if(!var)
        return (0);
    window_settings(&var, mapi, x_len, y_len);
    

    free(mapi);

    
    
    mlx_loop((*var).mlx);
    return (0);
}

