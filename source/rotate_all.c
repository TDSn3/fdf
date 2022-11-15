/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:17:07 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/15 17:40:25 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	show_double_tab(t_data_util *d);

void	rotate_all(t_data_util *d, void *mlx, void *mlx_win, t_data_mlximg *img)
{
	int i = 0;
	int j = 0;
	float w = d->tab_widht;
	float h = d->tab_height;
	int	win_h_div = ((float)(d->win_height) / 2) + 0.5;
	int	win_w_div = ((float)(d->win_widht) / 2) + 0.5;
	int	x_o;
	int	y_o;
	int	x_next;
	int	y_next;
	
//	printf("tab_height = %d, tab_widht = %d\n", d->tab_height,d->tab_widht);
/*
	while (i < h)
	{
		while (j < w)
		{
//			printf("[%d][%d] %d\n", i, j, d->tab_hw[i][j]);
			x_o = win_h_div - (((h / 2) + 0.5) * d->square_size) + (i * d->square_size);
			y_o = win_w_div - (((w / 2) + 0.5) * d->square_size) + (j * d->square_size);
			x_next = win_h_div - (((h / 2) + 0.5) * d->square_size) + ((i + 1) * d->square_size);
			y_next = win_w_div - (((w / 2) + 0.5) * d->square_size) + ((j + 1) * d->square_size);

			if (i + 1 < h)
				line_put(rotate_pixel_x(win_h_div,	win_w_div,	x_o,	y_o, d, i, j) + (d->square_size / 1),
						 rotate_pixel_y(win_h_div,	win_w_div,	x_o, 	y_o, d, i, j),
						 rotate_pixel_x(win_h_div,	win_w_div,	x_next,	y_o, d , i + 1, j) + (d->square_size / 1),
						 rotate_pixel_y(win_h_div,	win_w_div,	x_next,	y_o, d , i + 1, j),
						 mlx, mlx_win, img, d, i, j, i + 1, j);
			if (j + 1 < w)
				line_put(rotate_pixel_x(win_h_div,	win_w_div,	x_o,	y_o, d, i, j) + (d->square_size / 1),
						 rotate_pixel_y(win_h_div,	win_w_div,	x_o,	y_o,d, i, j),
						 rotate_pixel_x(win_h_div,	win_w_div,	x_o,	y_next,d, i, j + 1) + (d->square_size / 1),
						 rotate_pixel_y(win_h_div,	win_w_div,	x_o,	y_next,d, i, j + 1),
						 mlx, mlx_win, img, d, i, j, i, j + 1);
			j++;
		}
//		printf("\n");
		j = 0;
		i++;
	}
*/

	i = 0;
	j = 0;
	while (i < h)
	{
		while (j < w)
		{
			x_o = win_h_div - (((h / 2) + 0.5) * d->square_size) + (i * d->square_size);
			y_o = win_w_div - (((w / 2) + 0.5) * d->square_size) + (j * d->square_size);
			x_next = win_h_div - (((h / 2) + 0.5) * d->square_size) + ((i + 1) * d->square_size);
			y_next = win_w_div - (((w / 2) + 0.5) * d->square_size) + ((j + 1) * d->square_size);
			
			d->pos_x[i][j] = rotate_pixel_x(win_h_div,	win_w_div,	x_o, 	y_o, d, i, j),
			d->pos_y[i][j] = rotate_pixel_y(win_h_div,	win_w_div,	x_o, 	y_o, d, i, j),
			j++;
		}
		j = 0;
		i++;
	}
//	show_double_tab(d);

	i = 0;
	j = 0;
	while (i < h)
	{
		while (j < w)
		{
			if (i + 1 < h)
				line_put(d->pos_x[i][j] + d->square_size,
						 d->pos_y[i][j],
						 d->pos_x[i + 1][j] + d->square_size,
						 d->pos_y[i + 1][j],
						 mlx, mlx_win, img, d, i, j, i + 1, j);
			if (j + 1 < w)
				line_put(d->pos_x[i][j] + d->square_size,
						 d->pos_y[i][j],
						 d->pos_x[i][j + 1] + d->square_size,
						 d->pos_y[i][j + 1],
						 mlx, mlx_win, img, d, i, j, i, j + 1);
			j++;
		}
		j = 0;
		i++;
	}
	
}
/*
	while (i < w)
	{
		while (j < h)
		{
			printf("%d %d\n", i, j);
			if (i + 1 < w)
				line_put(i * 10,
						 j* 10,
						 (i + 1) * 10,
						 j * 10,
						 mlx, mlx_win, img, d, i, j, i + 1, j);
			if (j + 1 < h)
				line_put(i* 10,
						 j* 10,
						 i * 10,
						 (j + 1) * 10,
						 mlx, mlx_win, img, d, i, j, i, j + 1);
			j++;
		}
		j = 0;
		i++;
	}
*/

static void	show_double_tab(t_data_util *d)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < d->tab_height)
	{
		while (j < d->tab_widht)
		{
			printf("%d,%d  ", d->pos_x[i][j], d->pos_y[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}