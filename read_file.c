/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:24:46 by sirvin            #+#    #+#             */
/*   Updated: 2020/01/14 12:24:47 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_wcount(char *line, char c)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_strsplit(line, c);
	while (str[i])
		i++;
	return (i);
}

int			get_w(char *file_name)
{
	int		w;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	w = ft_wcount(line, ' ');
	free(line);
	close(fd);
	return (w);
}

int			get_h(char *file_name)
{
	int		h;
	char	*line;
	int		fd;

	fd = open(file_name, O_RDONLY, 0);
	h = 0;
	while (get_next_line(fd, &line))
	{
		h++;
		free(line);
	}
	close(fd);
	return (h);
}

void		ft_preobrazov(int *z_line, char *str)
{
	char	**number;
	int		i;

	i = 0;
	number = ft_strsplit(str, ' ');
	while (number[i])
	{
		z_line[i] = ft_atoi(number[i]);
		free(number[i]);
		i++;
	}
	free(number);
}

void		read_file(char *file_name, fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->h = get_h(file_name);
	data->w = get_w(file_name);
	data->z_matr = (int **)malloc(sizeof(int*) * (data->h + 1));
	i = 0;
	while (i <= data->h)
		data->z_matr[i++] = (int*)malloc(sizeof(int*) * (data->w + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		ft_preobrazov(data->z_matr[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->z_matr[i] = NULL;
}
