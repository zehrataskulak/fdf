/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzehra <zzehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:34:27 by zzehra            #+#    #+#             */
/*   Updated: 2025/12/08 20:58:50 by zzehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_len_check_map(char *argv, int argc, int *x_len, int *y_len)
{
	if (argc != 2)
	{
		write(2, "Invalid number of argument!\n", 28);
		exit(1);
	}
	(*x_len) = find_x_or_y(argv, 'x');
	if ((*x_len) == 0)
	{
		write(2, "Invalid Map!\n", 13);
		exit(1);
	}
	(*y_len) = find_x_or_y(argv, 'y');
}

int	main(int argc, char **argv)
{
	int		y_len;
	int		x_len;
	t_vars	*var;
	t_map	*map;

	get_len_check_map(argv[1], argc, &x_len, &y_len);
	read_map(argv[1], &map, x_len, y_len);
	find_isometric(map, x_len, y_len);
	var = malloc(sizeof(t_vars));
	if (!var)
		return (0);
	window_settings(&var, map, x_len, y_len);
	free(map);
	mlx_loop((*var).mlx);
	return (0);
}
