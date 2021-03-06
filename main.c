/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:24:33 by sirvin            #+#    #+#             */
/*   Updated: 2020/01/14 12:24:34 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

int		deal_key(int key, fdf *data)
{
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 126)
		data->shift_y = data->shift_y - 10;
	if (key == 125)
		data->shift_y = data->shift_y + 10;
	if (key == 123)
		data->shift_x = data->shift_x - 10;
	if (key == 124)
		data->shift_x = data->shift_x + 10;
	if (key == 69)
		data->zoom = data->zoom + 10;
	if (key == 76)
		data->zoom = data->zoom - 10;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_draw(data);
	return (0);
}

int		main(int argc, char **argv)
{
	fdf *data;

	data = (fdf*)malloc(sizeof(fdf));
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 20;
	ft_draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
