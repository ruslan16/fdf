/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:24:19 by sirvin            #+#    #+#             */
/*   Updated: 2020/01/14 12:24:23 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define MAX1(a, b) (a > b ? a : b)

float	mod(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

void		soed_toch(float x, float y, float x1, float y1, fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->z_matr[(int)y][(int)x];
	z1 = data->z_matr[(int)y1][(int)x1];
	ft_zoom(&x, &y, data);
	ft_zoom(&x1, &y1, data);
	ft_color(z, z1, data);
	ft_3d(&x, &y, z, data);
	ft_3d(&x1, &y1, z1, data);
	ft_shift(&x, &y, data);
	ft_shift(&x1, &y1, data);
	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX1(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	ft_draw(fdf *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->h)
	{
		x = 0;
		while (x < data->w)
		{
			if (x < data->w - 1)
				soed_toch(x, y, x + 1, y, data);
			if (y < data->h - 1)
				soed_toch(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
