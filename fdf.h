/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:35:10 by sirvin            #+#    #+#             */
/*   Updated: 2020/01/14 12:35:13 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include "minilibx_macos/mlx.h"

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct
{
	int		w;
	int		h;
	int		**z_matr;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	int		cos;
	int		sin;

	void	*mlx_ptr;
	void	*win_ptr;
}			fdf;

#endif

void	read_file(char *file_name, fdf *data);
void	ft_preobrazov(int *z_line, char *str);
int		get_h(char *file_name);
int		get_w(char *file_name);
int		ft_wcount(char *line, char c);
int		main(int argc, char **argv);
void	soed_toch(float x, float y, float x1, float y1, fdf *data);
float	mod(float i);
int		deal_key(int key, fdf *data);
void	ft_draw(fdf *data);
void	ft_3d(float *x, float *y, int z, fdf *data);
void	ft_zoom(float *x, float *y, fdf *data);
void	ft_shift(float *x, float *y,fdf *data);
void	ft_color(int z, int z1, fdf *data);
void	ft_bonus(float x, float y, int z, fdf *data);