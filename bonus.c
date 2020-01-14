/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:32:59 by sirvin            #+#    #+#             */
/*   Updated: 2020/01/14 13:33:00 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(float *x, float *y, fdf *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
}

void	ft_shift(float *x, float *y, fdf *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	*x += data->shift_x;
	*y += data->shift_y;
}

void	ft_color(int z, int z1, fdf *data)
{
	if (z || z1 > 0)
		data->color = 0xe80c0c;
	else if (z || z1 == 0)
		data->color = 0xffffff;
	else
		data->color = 0xffff00;
}

void	ft_3d(float *x, float *y, int z, fdf *data)
{
	*x = (*x - *y) * cos(1);
	*y = (*x + *y) * sin(1) - z;
}
